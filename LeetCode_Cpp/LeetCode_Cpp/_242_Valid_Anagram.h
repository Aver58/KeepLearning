#pragma once
/*
给定两个字符串 s 和 t，编写一个函数来判断 t 是否是 s 的字母异位词。
说明：你可以假设字符串只包含小写字母。

示例 1
输入: s = 'anagram', t = 'nagaram'
输出: true

示例 2
输入: s = 'rat', t = 'car'
输出: false

字母异位词，也就是两个字符串中的相同字符的数量要对应相等。
例如，s 等于 “anagram”，t 等于 “nagaram”，s 和 t 就互为字母异位词。
因为它们都包含有三个字符 a，一个字符 g，一个字符 m，一个字符 n，以及一个字符 r。
而当 s 为 “rat”，t 为 “car”的时候，s 和 t 不互为字母异位词。
*/

#include "Global.h"

class _242_Valid_Anagram
{
public:
	void Test() {
		string s = "anagram";
		string t = "nagaram";
		std::cout << _242_Valid_Anagram::isAnagram(s,t);
	}

	bool isAnagram(string s,string t) {
		// 提示：字符出现次数一样就是异位词
		//1. 用2个字符数组，字符出现次数，最后比较两个字符数组是否一致
		

		//2. 用1个字符数组，第一个字符串时候记录出现次数，第二个字符串时候，减掉出现次数，最后都为0就一致
		// array 8ms 97%
		if (s.size() != t.size()) return false;
		int help[26] = { 0 };
		for (int i = 0; i < s.size(); ++i) {
			++help[s[i] - 'a'];
			--help[t[i] - 'a'];
		}
		for (int i = 0; i < 26; ++i) {
			if (help[i] != 0) return false;
		}
		return true;

		//map  16ms 62.5%
	/*	if (s.size() != t.size()) {
			return false;
		}
		unordered_map<char, int> umap;
		for (int i = 0; i < s.size(); ++i) {
			++umap[s[i]];
			--umap[t[i]];
		}
		for (auto c : umap) {
			if (c.second != 0) {
				return false;
			}
		}

		return true;*/
	}
};

