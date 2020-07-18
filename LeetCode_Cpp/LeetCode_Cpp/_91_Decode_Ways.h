#pragma once

/*

A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

*/

#include "Global.h"

class _91_Decode_Ways
{
public:
	void Test() {
		string head = "226";
		_91_Decode_Ways::numDecodings(head);
	}

	int numDecodings(string s) {
		// 动态规划
		if (s[0] == '0')
			return 0;
		// 分情况讨论：
		// 1. s[i] = '0',前面是1还是2都是只有一种编码方式
		// 2. s[i - 1] == '1' ==> dp[i] = dp[i-1] + dp[i-2]
		// 3. s[i - 1] == '2' && s[i] >= 1 and s[i] <= 6 ==> dp[i] = dp[i-1] + dp[i-2]
		int count = 1;
		int preCount = 1;
		for(int i = 1; i < s.size(); i++)
		{
			int tmp = count;
			if (s[i] == '0')
			{
				if (s[i - 1] == '1' || s[i - 1] == '2') count = preCount;
				else return 0;
			}
			else if (s[i - 1] == '1' || ((s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6')))
			{
				count += preCount;
			}
			preCount = tmp;
		}
		return count;

		// 递归版本：
		//dp[i] = dp[i - 1] + dp[i - 2]
	}
};