#pragma once
/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include "Global.h"

class _1_Two_Sum
{
public:
	void Test() {
		vector<int> head{ 3,2,4 };
		vector<int> result = _1_Two_Sum::twoSum(head,6);
		for (size_t i = 0; i < result.size(); i++)
		{
			cout << result[i];
		}
	}

	vector<int> twoSum(vector<int>& nums, int target) {
		// 1. O（n^2）184 ms 46%
		int size = nums.size();
		if (size < 2)
			return vector<int>{};
		//for (int i = 0; i < size - 1; i++)
		//{
		//	for (int j = i+1; j < size; j++)
		//	{
		//		if (nums[i] + nums[j] == target)
		//		{
		//			return vector<int>{ i,j };
		//		}
		//	}
		//}

		//2. map    O（n）
		map<int, int> targetMap;
		for (int i = 0; i < size; i++)
		{
			map<int, int>::iterator it = targetMap.find(nums[i]);
			if (it!= targetMap.end())
			{
				return vector<int>{ i, it->second };
			}
			else
			{
				targetMap[target - nums[i]] = i;
			}
		}

		return vector<int>{};
	}
};

