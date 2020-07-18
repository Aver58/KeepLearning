#pragma once

/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

Example 1:

Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/

#include "Global.h"

class _70_Climbing_Stairs
{
private:


public:
	void Test() {
		_70_Climbing_Stairs::climbStairs(3);
	}

	int climbStairs(int n) {
		// 爬楼梯，斐波那契数列
		//int dp[n]{ 0 };
		if (n == 1)
			return 1;
		vector<int> dp(n, 0);
		dp[0] = 1;
		dp[1] = 2;
		for (size_t i = 2; i < n; i++)
		{
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[(int)(n - 1)];
	}
};