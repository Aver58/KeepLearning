#pragma once
/*
Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

Example 1:
Input:

"bbbab"
Output:
4
One possible longest palindromic subsequence is "bbbb".
Example 2:
Input:

"cbbd"
Output:
2
One possible longest palindromic subsequence is "bb".
*/

#include "Global.h"

class _516_Longest_Palindromic_Subsequence
{
private:
	string longestPalindromic = "";

public:
	void Test() {
		string s = "cbbd";
		std::cout << _516_Longest_Palindromic_Subsequence::longestPalindromeSubseq(s);
	}

	//bool IsPalindrome(string s) {
	//	for (size_t i = 0; i < s.length/2; i++)
	//	{
	//		if (s[i] != s[s.length - 1 - i])
	//		{
	//			return false;
	//		}
	//	}
	//	return true;
	//}

	int longestPalindromeSubseq(string s) {
		//区间规划
		//区间规划，就是说各个子问题的规模由不同的区间来定义，一般子问题的最佳状态或结果存储在二维数组里。
		//一般用 dp[i][j] 代表从第 i 个位置到第 j 个位置之间的最佳状态或结果。
        int n = s.size();
        // 定义 dp 矩阵，dp[i][j] 表示从字符串第 i 个字符到第 j 个字符之间的最长回文
		vector<vector<int> > dp(n, vector<int>(n, 0));

        // 初始化 dp 矩阵，将对角线元素设为 1，即单个字符的回文长度为 1
        for (int i = 0; i < n; i++) dp[i][i] = 1;

        // 从长度为 2 开始，尝试将区间扩大，一直扩大到 n
        for (int len = 2; len <= n; len++) {
            // 在扩大的过程中，每次都得出区间的其实位置i和结束位置j
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                // 比较一下区间首尾的字符是否相等，如果相等，就加2；如果不等，从规模更小的字符串中得出最长的回文长度
                if (s[i] == s[j]) {
                    dp[i][j] = 2 + (len == 2 ? 0 : dp[i + 1][j - 1]);
                }
                else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][n - 1];
	}
};