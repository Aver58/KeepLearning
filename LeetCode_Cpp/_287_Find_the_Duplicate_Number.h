#include "Global.h"

/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
Example 3:

Input: nums = [1,1]
Output: 1
Example 4:

Input: nums = [1,1,2]
Output: 1
 

Constraints:

2 <= n <= 3 * 104
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.
 

Follow up:

How can we prove that at least one duplicate number must exist in nums?
Can you solve the problem without modifying the array nums?
Can you solve the problem using only constant, O(1) extra space?
Can you solve the problem with runtime complexity less than O(n2)?
*/


#pragma once
class _287_Find_the_Duplicate_Number
{
public:
	static void Test() {
		vector<int> Input{ 1,3,4,2,2 };
		cout << findDuplicate(Input);
	}

	static int findDuplicate(vector<int>& nums) {
		// 1. hashSet空间换时间
		// 2. 把当前数字对应下标的数字取负，如果已经是负数说明出现过了，直接返回当前数字的绝对值。
		int temp = 0;
		for (size_t i = 0; i < nums.size(); i++)
		{
			int source = abs(nums[i]);
			int target = nums[source];
			if (target <= 0)
				return abs(source);
			else
				nums[source] = -target;
		}
		return -1;
	}
};

