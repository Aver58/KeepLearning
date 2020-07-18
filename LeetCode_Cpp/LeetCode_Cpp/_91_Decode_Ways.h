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

2262


*/

#include "Global.h"

class _91_Decode_Ways
{
public:
	void Test() {
		string head = "12";
		_91_Decode_Ways::numDecodings(head);
	}

	int numDecodings(string s) {
		//1位数编码1次，
		int count = 0;

	}
};