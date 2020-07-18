#pragma once

/*

Given an array of strings, group anagrams together.
//给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.

*/

#include "Global.h"

class _49_Group_Anagrams
{
public:
	void Test() {
		vector<string> head{ "eat", "tea", "tan", "ate", "nat", "bat" };
		_49_Group_Anagrams::groupAnagrams(head);
	}

	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		int size = strs.size();
		if (size < 1)
			return vector<vector<string>>{};
		// 1. 排序后相等的字符串是异位词
		// todo


		// 2. 异位词【质数！！】乘积相同，做个map
		//26个字母的质数对应表
		int char_hash[26] = {
			2,  3,  5,  7,  11,
			13, 17, 19, 23, 29,
			31, 37, 41, 43, 47,
			53, 59, 61, 67, 71,
			73, 79, 83, 89, 97,
			101
		};

		map<int, int> hashMap;
		vector<vector<string>> res;
		for (size_t i = 0; i < size; i++)
		{
			string str = strs[i];
			if (str == "")
				continue;
			int hash_key = 1;
			for (auto ch : str)
			{
				hash_key *= char_hash[ch - 'a'];
			}

			if (hashMap.count(hash_key) > 0)
			{
				res[hashMap[hash_key]].push_back(str);
			}
			else
			{
				hashMap[hash_key] = i;
				res[res.size()].push_back(str);
			}
		}
		return res;
	}
};