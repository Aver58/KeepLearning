#pragma once
/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
			 Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

#include "Global.h"

class _3_Longest_Substring_Without_Repeating_Characters
{
public:
	void Test() {
		_3_Longest_Substring_Without_Repeating_Characters::lengthOfLongestSubstring("abcabcbb");
	}

	int lengthOfLongestSubstring(string s) {
		if (s.size() == 0) return 0;
		// 1. set + ����ָ��
		// ����һ����ϣ���� set����ʼ����� max Ϊ 0
		//unordered_set<char> lookup;
		//int left, maxLen = 0;
		//// �ÿ���ָ�� i �� j ɨ��һ���ַ����������ָ����ָ����ַ��Ѿ������ڹ�ϣ��������ϵس��Խ���ָ����ָ����ַ��ӹ�ϣ������ɾ��
		//for (size_t right = 0; right < s.length(); right++)
		//{
		//	while (lookup.find(s[right])!=lookup.end())
		//	{
		//		lookup.erase(s[left]);
		//		left++;
		//	}
		//	// ����ָ����ַ����뵽��ϣ���Ϻ󣬸���һ�½�� max
		//	maxLen = max(maxLen, right - left + 1);
		//	lookup.insert(s[right]);
		//}
		//return maxLen;

		//2. map + �������ڣ�
		map<char, int> charMap;
		int maxLen = 0;
		for (size_t left = 0, right = 0; left < s.length(); right++)
		{
			if (charMap.find(s[right]) != charMap.end())
			{
				left = max(left, charMap[s[right]]);
			}
			maxLen = max(maxLen, right - left + 1);
			charMap[s[left]] = right;
		}
		return maxLen;
	}
};

