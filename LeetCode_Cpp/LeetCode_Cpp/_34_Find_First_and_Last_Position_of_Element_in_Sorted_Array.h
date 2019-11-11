#pragma once
/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include "Global.h"

class _34_Find_First_and_Last_Position_of_Element_in_Sorted_Array
{
public:
	static void Test() {
		vector<int> head{ 2,2 };
		_34_Find_First_and_Last_Position_of_Element_in_Sorted_Array::searchRange(head,2);
	}

	// 寻找边界（二合一版本）
	static int extremeInsertionIndex(vector<int>& nums, int target, bool isLeft) {
		int left = 0;
		int right = nums.size();

		// [left,right) 终止条件是left==right
		while (left < right) 
		{
			int mid = (left + right) >> 1;
			if (target < nums[mid] || (isLeft && target == nums[mid]))
			{
				right = mid;
			}
			else 
			{
				left = mid + 1;
			}
		}

		return left;
	}

	// 左边边界
	// 以当 nums[mid] == target 时不要立即返回 
	// 收紧右侧边界以锁定左侧边界
	static int FindLeftBound(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size();
		while (left < right)
		{
			int mid = (left + right) >> 1;
			if (target == nums[mid])
			{
				right = mid;// 注意
			}
			else if (target < nums[mid])
			{
				right = mid;
			}
			else if (target > nums[mid])
			{
				left = mid + 1;
			}
		}
		return left;
	}

	// 右边边界
	// 收紧左侧边界以锁定右侧边界 
	static int FindRightBound(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size();
		//因为我们初始化 right = nums.length
		//所以决定了我们的「搜索区间」是[left, right)
		while (left < right)
		{
			int mid = (left + right) >> 1;
			if (target == nums[mid])
			{
				left = mid + 1;// 注意
				//mid = left - 1
			}
			else if (target < nums[mid])
			{
				right = mid;
			}
			else if (target > nums[mid])
			{
				left = mid + 1;
			}
		}
		// 其实left或者right都一样，最后left == right
		return right - 1;// 注意
		/*if (nums[mid] == target) {
			left = mid + 1;
			// 这样想: mid = left - 1
		*/
	}


	// https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/solution/er-fen-cha-zhao-suan-fa-xi-jie-xiang-jie-by-labula/
	static vector<int> searchRange(vector<int>& nums, int target) {
		//1. 二分法 8 ms 93%
		vector<int> targetRange = { -1, -1 };

		int leftIdx = extremeInsertionIndex(nums, target, true);

		// assert that `leftIdx` is within the array bounds and that `target`
		// is actually in `nums`.
		if (leftIdx == nums.size() || nums[leftIdx] != target) {
			return targetRange;
		}

		targetRange[0] = leftIdx;
		targetRange[1] = extremeInsertionIndex(nums, target, false) - 1;

		return targetRange;
	}
};

