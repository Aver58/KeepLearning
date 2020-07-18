#pragma once
/*
Given an integer array with all positive numbers and no duplicates, 
find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.
 

Follow up:
What if negative numbers are allowed in the given array?
How does it change the problem?
What limitation we need to add to the question to allow negative numbers?

Credits:
Special thanks to @pbrother for adding this problem and creating all test cases.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum-iv
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

#include "Global.h"

class _377_Combination_Sum_IV
{
private:
	vector<int> candidates;
	int size;

public:
	void Test() {
		vector<int> head{ 1, 2, 3,4 };
		cout<< _377_Combination_Sum_IV::combinationSum4(head, 4);
	}

	int DFS(int target,vector<int>& dp) {
		// 用减法，递归减去每个子节点，当target = 0的时候，得到一种答案，答案数量+1
		if (dp[target] > 0) return dp[target];
		if (0 == target) return 1;
		int ans = 0;
		for (int i = 0; i < size && target - candidates[i] >= 0; i++)
		{
			ans += DFS(target - candidates[i], dp);
		}
		// 得到每个target的排序都是一样的，不要重复计算，用数组记录下来。下标就是target
		dp[target] = ans;
		return ans;
	}

	int combinationSum4(vector<int>& nums, int target) {
		//1. 回溯法
		//2. 记忆法回溯dp
		//this->candidates = nums;
		//this->size = nums.size();
		//vector<int> dp (target + 1,0);
		//dp[0] = 1;
		//return DFS(target, dp);
		////3. 动态规划（自底向上）
		////首先计算粒度最小的问题
		////然后计算粒度更大的问题，直到问题规模达到输入规模
		////dp[1] = dp[0] = 1;
		////dp[2] = dp[1] + dp[0] = 2;
		////dp[3] = dp[2] + dp[1] + dp[0] = 4;
		////dp[4] = dp[4 - 1] + dp[4 - 2] + dp[4 - 3] = dp[3] + dp[2] + dp[1] = 7
		//long *dp = new long[target + 1];
		//dp[0] = 1;
		//for (int i = 1; i < target + 1; i++)dp[i] = 0;

		//for (int i = 1; i <= target; i++)
		//{
		//	for (int j = 0; j < nums.size(); j++)
		//	{
		//		if (nums[j] <= i)
		//		{

		//			dp[i] += dp[i - nums[j]];
		//			if (dp[i] > INT_MAX)dp[i] %= INT_MAX;
		//		}
		//	}
		//}
		//return dp[target];
	}
};

