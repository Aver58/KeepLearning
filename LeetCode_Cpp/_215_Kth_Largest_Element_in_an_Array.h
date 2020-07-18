#pragma once
/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
*/

#include "Global.h"

class _215_Kth_Largest_Element_in_an_Array
{
public:
	void Test() {
		vector<int> nums{ 7,6,5,4,3,2,1 };
		int res = findKthLargest(nums,2);
		cout << res;
	}

	int _QuickSort(vector<int>& nums, int left,int right) {
		// 随机pivot
		int pivot_index = rand() % (right - left + 1) + left;
		// 先将pivot值存放在right
		swap(nums[pivot_index], nums[right]);

		int i = left;
		//遍历所有值和基准值比较，比基准值小的，放到指针i的位置
		for (int j = left; j < right; j++)
		{
			if (nums[j] < nums[right])
			{
				swap(nums[j], nums[i++]);
			}
		}
		// 把基准值放到指针i的位置
		swap(nums[i], nums[right]);

		return i;

		/*
		//② 随机pivot
		//要取得[a, b] 的随机整数，使用(rand() % (b - a + 1)) + a;
		int pivot_index = rand() % (right - left + 1) + left;
		swap(nums[left], nums[pivot_index]);
		int pivot = nums[left];
		while(left<right)
		{
			// 在基准值右边找一个比基准值小的
			while(right>left && nums[right]<=pivot)
				--right;

			nums[left] = nums[right];

			// 在基准值左边找一个比基准值大的
			while(right>left && nums[left]>=pivot)
				++left;

			nums[right] = nums[left];
		}
		// 把基准值放到指针left和right碰面的位置
		nums[left] = pivot;
		return left;
		*/

	}
	
	void QuickSort(vector<int>& nums, int left, int right) {
		if (left >= right) return;

		int pivot = _QuickSort(nums, left, right);//分成左右两半，一半不大于A[r], 一半不小于A[r]
		QuickSort(nums, left, pivot - 1); // 递归左边
		QuickSort(nums, pivot + 1, right);// 递归右边
	}

	int findKthLargest(vector<int>& nums, int k) {
		if (k <= 0 || k > nums.size()) return -1;
		//① sort 12 ms 82.31%
		//std::sort(nums.begin(), nums.end());
		//return nums[nums.size() - k];

		// ②quick sort
		// 找一个基准值，小的都放左边，大的都放右边
		// 递归
		QuickSort(nums, 0,nums.size()-1);
		return nums[nums.size() - k];
	}
};