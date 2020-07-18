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
		//����滮
		//����滮������˵����������Ĺ�ģ�ɲ�ͬ�����������壬һ������������״̬�����洢�ڶ�ά�����
		//һ���� dp[i][j] ����ӵ� i ��λ�õ��� j ��λ��֮������״̬������
        int n = s.size();
        // ���� dp ����dp[i][j] ��ʾ���ַ����� i ���ַ����� j ���ַ�֮��������
		vector<vector<int> > dp(n, vector<int>(n, 0));

        // ��ʼ�� dp ���󣬽��Խ���Ԫ����Ϊ 1���������ַ��Ļ��ĳ���Ϊ 1
        for (int i = 0; i < n; i++) dp[i][i] = 1;

        // �ӳ���Ϊ 2 ��ʼ�����Խ���������һֱ���� n
        for (int len = 2; len <= n; len++) {
            // ������Ĺ����У�ÿ�ζ��ó��������ʵλ��i�ͽ���λ��j
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                // �Ƚ�һ��������β���ַ��Ƿ���ȣ������ȣ��ͼ�2��������ȣ��ӹ�ģ��С���ַ����еó���Ļ��ĳ���
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