/*
写一个简单不加括号正则表达式，如果不合法就返回false
int calcu(char *str, int n )
{
	int i, j, k;
	float res;

	int SIZE_1 = (n / 2 + 1)*sizeof(int);
	int SIZE_2 = n / 2;
	float* num = new float[SIZE_1];
	char* exp = new char[SIZE_2];

	for (i = 0, j = 0, k = 0; i<n; i++)
	{
		if (i % 2 == 0)
			num[j++] = str[i] - '0';
		else
			exp[k++] = str[i];
	}
	//----------乘除--------
for (i = 0, j = 1; i < n / 2; ++i)
{
	if (exp[i] != '*'&&exp[i] != '/')
	{
		j = 1;
		continue;
	}
	if (exp[i] == '*')
	{
		num[i + 1] *= num[i];
		for (k = 0; k < j; k++)
		{
			num[i - k] = num[i + 1];
		}
		j++;
	}
	else if (exp[i] == '/')
	{
		num[i + 1] = num[i] / num[i + 1];
		for (k = 0; k < j; k++)
		{
			num[i - k] = num[i + 1];
		}
		j++;
	}
}
//----------加减--------
res = num[0];
for (i = 0, j = 1; i < n / 2; i++)
{
	if (exp[i] == '+')
		res += num[i + 1];
	else if (exp[i] == '-')
		res -= num[i + 1];
}

delete num;
num = nullptr;

delete exp;
exp = nullptr;

return res;
}


//输出链表中点，智力题
struct ListNode{
	int val;
	ListNode* next;
};

int len(ListNode* head)
{
	int n=0;
	ListNode * node=head;
	while(node!=nullptr)
	{
		n++;
		node=node->next;
	}
}
ListNode * find(ListNode* head)
{
	int length=len(head);
	int n=0;

	if(length&1)
		n=length/2+1;
	else
		n=length/2;

	ListNode* node=head;
	for(int i=1;i<=n;i++)
	{
		node=node->next;
	}

	return node;
}

ListNode* find(ListNode* head)
{

	ListNode* p1=head->next;
	ListNode* p2=p1->next;

	while(p2!=nullptr&&p2->next!=nullptr)
	{
		p1=p1->next;
		p2=p2->next->next;
	}
	return p1;
}

1. C++ 基础：多态
class A{
public:
	virtual void fun(){
		cout << "a" << endl;
	}
};
class B :A{
	virtual void fun(){
		cout << "b" << endl;
	}
};

笔试：
1. 给定一个字符串(s)和一个字符模式（p）。实现支持'.'和'*'的正则表达式匹配
'.'匹配任意单个字符
'*'匹配零个或者多个前面的元素
匹配应该覆盖整个字符串(s),而不是部分字符串
说明：
	s可能为空，且只包含a-z的小写字母
	p可能为空，且只包含a-z的小写字母,以及'.'和'*'字符
//----1 正则表达------
class Solution {
public:
	bool Ismatch(char* s, char* p)
	{
		if (!s || !p)
			return false;
		return match(s, p);
	}
	bool match(char* s, char* p)
	{
		if (*s == '\0'&&*p == '\0')
			return true;
		if (*s != '\0'&&*p == '\0')
			return false;

		if (*(p + 1) == '*')
		{
			if ((*p == *s) || (*p == '.'&&*s != '\0'))
			{
				return match(s + 1, p + 2) || match(s + 1, p) || match(s, p + 2);
			}
			else
				return match(s, p + 2);
		}
		if (*p == *s || (*p == '.'&&*s != '\0'))
		{
			return match(s + 1, p + 1);
		}
		return false;
	}
};

3. 编写一个程序，找到两个单链表相交的起始节点。

 

例如，下面的两个链表：

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
在节点 c1 开始相交。

 

注意：

如果两个链表没有交点，返回 null.
在返回结果后，两个链表仍须保持原有的结构。
可假定整个链表结构中没有循环。
程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。
//-----3 链表交点------

struct ListNode {
	int val;
	ListNode* next;
};
int len(ListNode *head)
{
	int n = 0;
	ListNode *node = head;
	while (node != nullptr)
	{
		n++;
		node = node->next;
	}
	return n;
}
ListNode * getIntersectionNode(ListNode *H1, ListNode* H2)
{
	int n1 = len(H1);
	int n2 = len(H2);
	int n = n1 - n2;

	ListNode *Long = H1;
	ListNode *Short = H2;

	if (n2 > n1)
	{
		Long = H2;
		Short = H1;
		n = n2 - n1;
	}
	for (int i = 0; i < n; i++)
	{
		Long = Long->next;
	}
	while ((Long != nullptr) && (Short != nullptr) && (Long != Short))
	{
		Long = Long->next;
		Short = Short->next;
	}
	ListNode *Fnode = Long;

	return Fnode;
}

2. 给定一个Weather表，编写一个SQL查询，来查找与之前（昨天的）日期相比温度更高的所有日期的ID
根据上述给定的Weather表格，返回id
*/
class unity_test {
public:
  
};

