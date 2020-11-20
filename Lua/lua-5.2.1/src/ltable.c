/*
** $Id: ltable.c,v 2.71 2012/05/23 15:37:09 roberto Exp $
** Lua tables (hash)
** See Copyright Notice in lua.h
*/


/*
** Implementation of tables (aka arrays, objects, or hash tables).
** Tables keep its elements in two parts: an array part and a hash part.
** Non-negative integer keys are all candidates to be kept in the array
** part. The actual size of the array is the largest `n' such that at
** least half the slots between 0 and n are in use.
** Hash uses a mix of chained scatter table with Brent's variation.
** A main invariant of these tables is that, if an element is not
** in its main position (i.e. the `original' position that its hash gives
** to it), then the colliding element is in its own main position.
** Hence even when the load factor reaches 100%, performance remains good.
*/

#include <string.h>

#define ltable_c
#define LUA_CORE

#include "lua.h"

#include "ldebug.h"
#include "ldo.h"
#include "lgc.h"
#include "lmem.h"
#include "lobject.h"
#include "lstate.h"
#include "lstring.h"
#include "ltable.h"
#include "lvm.h"


/*
** max size of array part is 2^MAXBITS
*/
#if LUAI_BITSINT >= 32
#define MAXBITS		30
#else
#define MAXBITS		(LUAI_BITSINT-2)
#endif

#define MAXASIZE	(1 << MAXBITS)


#define hashpow2(t,n)		(gnode(t, lmod((n), sizenode(t))))

#define hashstr(t,str)		hashpow2(t, (str)->tsv.hash)
#define hashboolean(t,p)	hashpow2(t, p)


/*
** for some types, it is better to avoid modulus by power of 2, as
** they tend to have many 2 factors.
*/
#define hashmod(t,n)	(gnode(t, ((n) % ((sizenode(t)-1)|1))))


#define hashpointer(t,p)	hashmod(t, IntPoint(p))


#define dummynode		(&dummynode_)

#define isdummy(n)		((n) == dummynode)

static const Node dummynode_ = {
  {NILCONSTANT},  /* value */
  {{NILCONSTANT, NULL}}  /* key */
};


/*
** hash for lua_Numbers
*/
static Node* hashnum(const Table* t, lua_Number n) {
	int i;
	luai_hashnum(i, n);
	if (i < 0) {
		if (cast(unsigned int, i) == 0u - i)  /* use unsigned to avoid overflows */
			i = 0;  /* handle INT_MIN */
		i = -i;  /* must be a positive value */
	}
	return hashmod(t, i);
}



/*
** returns the `main' position of an element in a table (that is, the index
** of its hash value)
*/
static Node* mainposition(const Table* t, const TValue* key) {
	switch (ttype(key)) {
	case LUA_TNUMBER:
		return hashnum(t, nvalue(key));
	case LUA_TLNGSTR: {
		TString* s = rawtsvalue(key);
		if (s->tsv.extra == 0) {  /* no hash? */
			s->tsv.hash = luaS_hash(getstr(s), s->tsv.len, s->tsv.hash);
			s->tsv.extra = 1;  /* now it has its hash */
		}
		return hashstr(t, rawtsvalue(key));
	}
	case LUA_TSHRSTR:
		return hashstr(t, rawtsvalue(key));
	case LUA_TBOOLEAN:
		return hashboolean(t, bvalue(key));
	case LUA_TLIGHTUSERDATA:
		return hashpointer(t, pvalue(key));
	case LUA_TLCF:
		return hashpointer(t, fvalue(key));
	default:
		return hashpointer(t, gcvalue(key));
	}
}


/*
** returns the index for `key' if `key' is an appropriate key to live in
** the array part of the table, -1 otherwise.
*/
static int arrayindex(const TValue* key) {
	if (ttisnumber(key)) {
		lua_Number n = nvalue(key);
		int k;
		lua_number2int(k, n);
		if (luai_numeq(cast_num(k), n))
			return k;
	}
	return -1;  /* `key' did not match some condition */
}


/*
** returns the index of a `key' for table traversals. First goes all
** elements in the array part, then elements in the hash part. The
** beginning of a traversal is signaled by -1.
*/
static int findindex(lua_State* L, Table* t, StkId key) {
	int i;
	if (ttisnil(key)) return -1;  /* first iteration */
	i = arrayindex(key);
	if (0 < i && i <= t->sizearray)  /* is `key' inside array part? */
		return i - 1;  /* yes; that's the index (corrected to C) */
	else {
		Node* n = mainposition(t, key);
		for (;;) {  /* check whether `key' is somewhere in the chain */
		  /* key may be dead already, but it is ok to use it in `next' */
			if (luaV_rawequalobj(gkey(n), key) ||
				(ttisdeadkey(gkey(n)) && iscollectable(key) &&
					deadvalue(gkey(n)) == gcvalue(key))) {
				i = cast_int(n - gnode(t, 0));  /* key index in hash table */
				/* hash elements are numbered after array ones */
				return i + t->sizearray;
			}
			else n = gnext(n);
			if (n == NULL)
				luaG_runerror(L, "invalid key to " LUA_QL("next"));  /* key not found */
		}
	}
}


int luaH_next(lua_State* L, Table* t, StkId key) {
	int i = findindex(L, t, key);  /* find original element */
	for (i++; i < t->sizearray; i++) {  /* 先遍历数组部分 */
		if (!ttisnil(&t->array[i])) {  /* a non-nil value? */
			setnvalue(key, cast_num(i + 1));
			setobj2s(L, key + 1, &t->array[i]);
			return 1;
		}
	}
	for (i -= t->sizearray; i < sizenode(t); i++) {  /* 再遍历哈希部分 */
		if (!ttisnil(gval(gnode(t, i)))) {  /* a non-nil value? */
			setobj2s(L, key, gkey(gnode(t, i)));
			setobj2s(L, key + 1, gval(gnode(t, i)));
			return 1;
		}
	}
	return 0;  /* no more elements */
}


/*
** {=============================================================
** Rehash
** ==============================================================
*/


static int computesizes(int nums[], int* narray) {
	int i;
	int twotoi;  /* 2^i */
	int a = 0;  /* number of elements smaller than 2^i */
	int na = 0;  /* number of elements to go to array part */
	int n = 0;  /* optimal size for array part */
	for (i = 0, twotoi = 1; twotoi / 2 < *narray; i++, twotoi *= 2) {
		if (nums[i] > 0) {
			a += nums[i];
			if (a > twotoi / 2) {  /* more than half elements present? */
				n = twotoi;  /* optimal size (till now) */
				na = a;  /* all elements smaller than n will go to array part */
			}
		}
		if (a == *narray) break;  /* all elements already counted */
	}
	*narray = n;
	lua_assert(*narray / 2 <= na && na <= *narray);
	return na;
}


static int countint(const TValue* key, int* nums) {
	int k = arrayindex(key);
	if (0 < k && k <= MAXASIZE) {  /* is `key' an appropriate array index? */
		nums[luaO_ceillog2(k)]++;  /* count as such */
		return 1;
	}
	else
		return 0;
}


static int numusearray(const Table* t, int* nums) {
	int lg;
	int ttlg;  /* 2^lg */
	int ause = 0;  /* summation of `nums' */
	int i = 1;  /* count to traverse all array keys */
	for (lg = 0, ttlg = 1; lg <= MAXBITS; lg++, ttlg *= 2) {  /* for each slice */
		int lc = 0;  /* counter */
		int lim = ttlg;
		if (lim > t->sizearray) {
			lim = t->sizearray;  /* adjust upper limit */
			if (i > lim)
				break;  /* no more elements to count */
		}
		/* count elements in range (2^(lg-1), 2^lg] */
		for (; i <= lim; i++) {
			if (!ttisnil(&t->array[i - 1]))
				lc++;
		}
		nums[lg] += lc;
		ause += lc;
	}
	return ause;
}


static int numusehash(const Table* t, int* nums, int* pnasize) {
	int totaluse = 0;  /* total number of elements */
	int ause = 0;  /* summation of `nums' */
	int i = sizenode(t);
	while (i--) {
		Node* n = &t->node[i];
		if (!ttisnil(gval(n))) {
			ause += countint(gkey(n), nums);
			totaluse++;
		}
	}
	*pnasize += ause;
	return totaluse;
}


static void setarrayvector(lua_State* L, Table* t, int size) {
	int i;
	luaM_reallocvector(L, t->array, t->sizearray, size, TValue);
	for (i = t->sizearray; i < size; i++)
		setnilvalue(&t->array[i]);
	t->sizearray = size;
}


static void setnodevector(lua_State* L, Table* t, int size) {
	int lsize;
	if (size == 0) {  /* no elements to hash part? */
		t->node = cast(Node*, dummynode);  /* use common `dummynode' */
		lsize = 0;
	}
	else {
		int i;
		lsize = luaO_ceillog2(size);
		if (lsize > MAXBITS)
			luaG_runerror(L, "table overflow");
		size = twoto(lsize);
		t->node = luaM_newvector(L, size, Node);
		for (i = 0; i < size; i++) {
			Node* n = gnode(t, i);
			gnext(n) = NULL;
			setnilvalue(gkey(n));
			setnilvalue(gval(n));
		}
	}
	t->lsizenode = cast_byte(lsize);
	t->lastfree = gnode(t, size);  /* all positions are free */
}


void luaH_resize(lua_State* L, Table* t, int nasize, int nhsize) {
	int i;
	int oldasize = t->sizearray;
	int oldhsize = t->lsizenode;
	Node* nold = t->node;  /* save old hash ... */
	if (nasize > oldasize)  /* 数组部分需要变长 */
		setarrayvector(L, t, nasize);
	/* 创建一个合适长度的哈希部分 */
	setnodevector(L, t, nhsize);
	if (nasize < oldasize) {  
		/* 数组部分需要缩短 */
		t->sizearray = nasize;
		/* re-insert elements from vanishing slice */
		for (i = nasize; i < oldasize; i++) {
			if (!ttisnil(&t->array[i]))
				luaH_setint(L, t, i + 1, &t->array[i]);
		}
		/* 缩短数组 */
		luaM_reallocvector(L, t->array, oldasize, nasize, TValue);
	}
	/* 把所有元素重新插入哈希部分*/
	for (i = twoto(oldhsize) - 1; i >= 0; i--) {
		Node* old = nold + i;
		if (!ttisnil(gval(old))) {
			/* doesn't need barrier/invalidate cache, as entry was
			   already present in the table */
			setobjt2t(L, luaH_set(L, t, gkey(old)), gval(old));
		}
	}
	if (!isdummy(nold))
		luaM_freearray(L, nold, cast(size_t, twoto(oldhsize))); /* 释放旧的数组 */
}


void luaH_resizearray(lua_State* L, Table* t, int nasize) {
	int nsize = isdummy(t->node) ? 0 : sizenode(t);
	luaH_resize(L, t, nasize, nsize);
}


static void rehash(lua_State* L, Table* t, const TValue* ek) {
	int nasize, na;
	//创建一个nums[32]的数组，nums[i]表示key值为int型，且key值在(2i-1, 2i]范围内
	//(lua脚本里table的int型下标，如t[1]的key在(2-1, 20]这个区间)，并且value不为nil的元素个数
	int nums[MAXBITS + 1];  /* nums[i] = number of keys with 2^(i-1) < k <= 2^i */
	int i;
	int totaluse;
	for (i = 0; i <= MAXBITS; i++) 
		nums[i] = 0;  /* 初始化值 */
	nasize = numusearray(t, nums);  /* 统计array在nums数组中，不同区间的分布情况 */
	totaluse = nasize;  /* 所以int型key数量*/
	totaluse += numusehash(t, nums, &nasize);  /* count keys in hash part */
	/* count extra key */
	nasize += countint(ek, nums);
	totaluse++;//因为新插入一个元素，因此total_element += 1
	/* 计算数组部分的最新尺寸 */
	na = computesizes(nums, &nasize);
	/* 真正的扩容操作 */
	luaH_resize(L, t, nasize, totaluse - na);
}



/*
** }=============================================================
*/


Table* luaH_new(lua_State* L) {
	Table* t = &luaC_newobj(L, LUA_TTABLE, sizeof(Table), NULL, 0)->h;
	t->metatable = NULL;
	t->flags = cast_byte(~0);
	t->array = NULL;
	t->sizearray = 0;
	setnodevector(L, t, 0);
	return t;
}


void luaH_free(lua_State* L, Table* t) {
	if (!isdummy(t->node))
		luaM_freearray(L, t->node, cast(size_t, sizenode(t)));
	luaM_freearray(L, t->array, t->sizearray);
	luaM_free(L, t);
}


static Node* getfreepos(Table* t) {
	while (t->lastfree > t->node) {
		t->lastfree--;
		if (ttisnil(gkey(t->lastfree)))
			return t->lastfree;
	}
	return NULL;  /* could not find a free place */
}



/*
** inserts a new key into a hash table; first, check whether key's main
** position is free. If not, check whether colliding node is in its main
** position or not: if it is not, move colliding node to an empty place and
** put new key in its main position; otherwise (colliding node is in its main
** position), new key goes to an empty position.
*/
TValue* luaH_newkey(lua_State* L, Table* t, const TValue* key) {
	Node* mp;
	if (ttisnil(key)) 
		luaG_runerror(L, "table index is nil");
	else if (ttisnumber(key) && luai_numisnan(L, nvalue(key)))
		luaG_runerror(L, "table index is NaN");

	mp = mainposition(t, key);
	if (!ttisnil(gval(mp)) || isdummy(mp))
	{  /* main position被占用 */
		Node* othern;
		Node* n = getfreepos(t);  /* 获取一个空闲的位置 */
		if (n == NULL) {  /* 没有空闲位置了 */
			rehash(L, t, key);  /* 扩容 */
			/* 调用'newkey'的时候注意缓存和GC边界*/
			return luaH_set(L, t, key);  /* 设置值 */
		}
		lua_assert(!isdummy(n));
		othern = mainposition(t, gkey(mp));
		if (othern != mp) {
			/* 冲突节点不是在它自己的main position上 */
			while (gnext(othern) != mp) 
				othern = gnext(othern);  /* 找到main position的前一个节点 */

			//移动冲突节点到空闲位置
			gnext(othern) = n;  /* redo the chain with `n' in place of `mp' */
			*n = *mp;  /* 复制冲突节点到一个空闲位置 (mp->next also goes) */
			gnext(mp) = NULL;  /* now `mp' is free */
			setnilvalue(gval(mp));
		}
		else {
			/* 冲突节点在它自己的main position上 */
			//移动新节点到一个空闲节点
			gnext(n) = gnext(mp);  /* chain new position */
			gnext(mp) = n;
			mp = n;
		}
	}
	setobj2t(L, gkey(mp), key);
	luaC_barrierback(L, obj2gco(t), key);
	lua_assert(ttisnil(gval(mp)));
	return gval(mp);
}


/*
** search function for integers
*/
const TValue* luaH_getint(Table* t, int key) {
	/* (1 <= key && key <= t->sizearray) */
	if (cast(unsigned int, key - 1) < cast(unsigned int, t->sizearray))
		return &t->array[key - 1];
	else {
		lua_Number nk = cast_num(key);
		Node* n = hashnum(t, nk);
		do {  /* check whether `key' is somewhere in the chain */
			if (ttisnumber(gkey(n)) && luai_numeq(nvalue(gkey(n)), nk))
				return gval(n);  /* that's it */
			else n = gnext(n);
		} while (n);
		return luaO_nilobject;
	}
}


/*
** search function for short strings
*/
const TValue* luaH_getstr(Table* t, TString* key) {
	Node* n = hashstr(t, key);
	lua_assert(key->tsv.tt == LUA_TSHRSTR);
	do {  /* check whether `key' is somewhere in the chain */
		if (ttisshrstring(gkey(n)) && eqshrstr(rawtsvalue(gkey(n)), key))
			return gval(n);  /* that's it */
		else n = gnext(n);
	} while (n);
	return luaO_nilobject;
}


/*
** main search function
*/
const TValue* luaH_get(Table* t, const TValue* key) {
	switch (ttype(key)) {
	case LUA_TNIL: return luaO_nilobject;
	case LUA_TSHRSTR: return luaH_getstr(t, rawtsvalue(key));
	case LUA_TNUMBER: {
		int k;
		lua_Number n = nvalue(key);
		lua_number2int(k, n);
		if (luai_numeq(cast_num(k), nvalue(key))) /* index is int? */
			return luaH_getint(t, k);  /* use specialized version */
		  /* else go through */
	}
	default: {
		Node* n = mainposition(t, key);
		do {  /* check whether `key' is somewhere in the chain */
			if (luaV_rawequalobj(gkey(n), key))
				return gval(n);  /* that's it */
			else n = gnext(n);
		} while (n);
		return luaO_nilobject;
		}
	}
}


/*
** beware: when using this function you probably need to check a GC
** barrier and invalidate the TM cache.
*/
TValue* luaH_set(lua_State* L, Table* t, const TValue* key) {
	const TValue* p = luaH_get(t, key);
	if (p != luaO_nilobject)
		return cast(TValue*, p);
	else return luaH_newkey(L, t, key);
}


void luaH_setint(lua_State* L, Table* t, int key, TValue* value) {
	const TValue* p = luaH_getint(t, key);
	TValue* cell;
	if (p != luaO_nilobject)
		cell = cast(TValue*, p);
	else {
		TValue k;
		setnvalue(&k, cast_num(key));
		cell = luaH_newkey(L, t, &k);
	}
	setobj2t(L, cell, value);
}


static int unbound_search(Table* t, unsigned int j) {
	unsigned int i = j;  /* i is zero or a present index */
	j++;
	/* find `i' and `j' such that i is present and j is not */
	while (!ttisnil(luaH_getint(t, j))) {
		i = j;
		j *= 2;
		if (j > cast(unsigned int, MAX_INT)) {  /* overflow? */
		  /* table was built with bad purposes: resort to linear search */
			i = 1;
			while (!ttisnil(luaH_getint(t, i))) i++;
			return i - 1;
		}
	}
	/* now do a binary search between them */
	while (j - i > 1) {
		unsigned int m = (i + j) / 2;
		if (ttisnil(luaH_getint(t, m))) j = m;
		else i = m;
	}
	return i;
}


/*
** Try to find a boundary in table `t'. A `boundary' is an integer index
** such that t[i] is non-nil and t[i+1] is nil (and 0 if t[1] is nil).
*/
int luaH_getn(Table* t) {
	unsigned int j = t->sizearray;
	if (j > 0 && ttisnil(&t->array[j - 1])) {
		/* there is a boundary in the array part: (binary) search for it */
		unsigned int i = 0;
		//二分查找
		while (j - i > 1) {
			unsigned int m = (i + j) / 2;
			if (ttisnil(&t->array[m - 1])) j = m;
			else i = m;
		}
		return i;
	}
	/* else must find a boundary in hash part */
	else if (isdummy(t->node))  /* hash part is empty? node hash表是否为空*/
		return j;  /* that is easy... */
	else return unbound_search(t, j);
}



#if defined(LUA_DEBUG)

Node* luaH_mainposition(const Table* t, const TValue* key) {
	return mainposition(t, key);
}

int luaH_isdummy(Node* n) { return isdummy(n); }

#endif
