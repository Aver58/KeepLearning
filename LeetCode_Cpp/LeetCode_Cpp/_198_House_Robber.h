#include "Global.h"

/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, 
the only constraint stopping you from robbing each of them is that 
adjacent houses have security system connected and it will automatically contact the police 
if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, 
determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
			 Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
			 Total amount you can rob = 2 + 9 + 1 = 12.
*/

#pragma once
class _198_House_Robber
{
public:
	void Test() {
		vector<int> Input{1,2,3,1};//����һ�������洢���� int
		_198_House_Robber::rob(Input);
	}

	int rob(vector<int>& nums) {
		int n = nums.size();
		// ��������Ϊ�ջ�������ֻ��һ��Ԫ�ص����
		if (n == 0) return 0;
		if (n == 1) return nums[0];

		int res = 0;
		int dp[n];
		dp[0] = nums[0];
		dp[1] = max(nums[0], nums[1]);
		// ����ÿ�� nums[i]���������������ѡ���ǲ�ѡ��Ȼ��ȡ���ֵ
		for (int i = 2; i < n; i++) {
			dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
		}
		return dp[n - 1];
	}
};

