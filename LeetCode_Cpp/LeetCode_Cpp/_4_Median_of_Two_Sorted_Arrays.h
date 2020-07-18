#pragma once
/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

#include "Global.h"

class _4_Median_of_Two_Sorted_Arrays
{
public:
	void Test() {
		vector<int> num1{1,3};
		vector<int> num2{2};
		_4_Median_of_Two_Sorted_Arrays::findMedianSortedArrays(num1,num2);
	}

	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		//1. 合并数组，找到中位数 
		//2. 双指针
		//假设 m+n = L 这个问题就转变为在两个有序数组中寻找第 k 小的数 f(k)，
		//当 L 是奇数的时候k = L/2，结果为 f(k + 1)；
		//而当 L 是偶数的时候，结果为 f(k) + f(k + 1) / 2。
		int m = nums1.size();
		int n = nums2.size();

	
	}
};

