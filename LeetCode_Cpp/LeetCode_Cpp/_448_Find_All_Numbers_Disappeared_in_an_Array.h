#pragma once
/*
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), 
some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? 
You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include "Global.h"

class _448_Find_All_Numbers_Disappeared_in_an_Array
{
public:
	static void Test() {
		vector<int> head{ 4,3,2,7,8,2,3,1 };
		_448_Find_All_Numbers_Disappeared_in_an_Array::findDisappearedNumbers(head);
	}

	static vector<int> findDisappearedNumbers(vector<int>& nums) {
		//数组的下标
		// 要求：时间复杂度O(n)，空间复杂度O（1），返回的列表不算额外空间
		//使用数组的下标来标记数字的出现于否，
		//通过一遍遍历即可标记出全部已经出现的数组
		//
		//方法一：标记符号，最后是正号的就是没出现过  140 ms  67.33%
		/*
		[4, 3, 2, 7, 8, 2, 3, 1] 初始数据
		[4, 3, 2, -7, 8, 2, 3, 1] 第一个数据 4 出现，将数组的第四个也就是下标 3 的数据修改为负数。 - 7 计算时，通过绝对值处理一下即可不影响数据的计算
		[4, 3, -2, -7, 8, 2, 3, 1]
		[4, -3, -2, -7, 8, 2, 3, 1]
		[4, -3, -2, -7, 8, 2, -3, 1]
		[4, -3, -2, -7, 8, 2, -3, -1]
		[4, -3, -2, -7, 8, 2, -3, -1]
		[4, -3, -2, -7, 8, 2, -3, -1]
		[-4, -3, -2, -7, 8, 2, -3, -1]
		*/
		//计算结束，数组的第五个，第六个依然为整数，证明 5, 6 没有出现

		/*size_t len = nums.size();
		vector<int> result;
		if (len == 0)
			return result;
		for (size_t i = 0; i < len; i++)
		{
			if (nums[(abs(nums[i]) - 1) % len] > 0)
			{
				nums[(abs(nums[i]) - 1) % len] = -nums[(abs(nums[i]) - 1) % len];
			}
		}

		for (size_t j = 0; j < len; j++)
		{
			if (nums[j] > 0)
				result.push_back(j + 1);
		}
		return result;*/

		//方法二：每次出现，加一个数组长度，最后比对数值，如果比数组长度还小的就是没出现过。
		//124 ms  82.16%

		size_t len = nums.size();
		vector<int> vec;
		if (len == 0)
			return vec;
		for (int i = 0; i < len; i++)
		{
			nums[(nums[i] - 1) % len] += len;
		}

		for (int j = 0; j < len; j++)
		{
			if (nums[j] <= len)
				vec.push_back(j + 1);
		}
		return vec;
	}
};

