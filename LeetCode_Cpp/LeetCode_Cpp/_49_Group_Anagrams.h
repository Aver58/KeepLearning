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

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/group-anagrams
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

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
	
	}
};