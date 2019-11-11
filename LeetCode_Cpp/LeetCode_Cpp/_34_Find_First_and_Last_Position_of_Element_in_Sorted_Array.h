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

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

#include "Global.h"

class _34_Find_First_and_Last_Position_of_Element_in_Sorted_Array
{
public:
	static void Test() {
		vector<int> head{ 2,2 };
		_34_Find_First_and_Last_Position_of_Element_in_Sorted_Array::searchRange(head,2);
	}

	// Ѱ�ұ߽磨����һ�汾��
	static int extremeInsertionIndex(vector<int>& nums, int target, bool isLeft) {
		int left = 0;
		int right = nums.size();

		// [left,right) ��ֹ������left==right
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

	// ��߽߱�
	// �Ե� nums[mid] == target ʱ��Ҫ�������� 
	// �ս��Ҳ�߽����������߽�
	static int FindLeftBound(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size();
		while (left < right)
		{
			int mid = (left + right) >> 1;
			if (target == nums[mid])
			{
				right = mid;// ע��
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

	// �ұ߽߱�
	// �ս����߽��������Ҳ�߽� 
	static int FindRightBound(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size();
		//��Ϊ���ǳ�ʼ�� right = nums.length
		//���Ծ��������ǵġ��������䡹��[left, right)
		while (left < right)
		{
			int mid = (left + right) >> 1;
			if (target == nums[mid])
			{
				left = mid + 1;// ע��
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
		// ��ʵleft����right��һ�������left == right
		return right - 1;// ע��
		/*if (nums[mid] == target) {
			left = mid + 1;
			// ������: mid = left - 1
		*/
	}


	// https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/solution/er-fen-cha-zhao-suan-fa-xi-jie-xiang-jie-by-labula/
	static vector<int> searchRange(vector<int>& nums, int target) {
		//1. ���ַ� 8 ms 93%
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

