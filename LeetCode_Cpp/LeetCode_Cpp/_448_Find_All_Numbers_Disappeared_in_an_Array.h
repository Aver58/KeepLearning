#pragma once
/*
Given an array of integers where 1 �� a[i] �� n (n = size of array), 
some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? 
You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
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
		//������±�
		// Ҫ��ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O��1�������ص��б������ռ�
		//ʹ��������±���������ֵĳ����ڷ�
		//ͨ��һ��������ɱ�ǳ�ȫ���Ѿ����ֵ�����
		//
		//����һ����Ƿ��ţ���������ŵľ���û���ֹ�  140 ms  67.33%
		/*
		[4, 3, 2, 7, 8, 2, 3, 1] ��ʼ����
		[4, 3, 2, -7, 8, 2, 3, 1] ��һ������ 4 ���֣�������ĵ��ĸ�Ҳ�����±� 3 �������޸�Ϊ������ - 7 ����ʱ��ͨ������ֵ����һ�¼��ɲ�Ӱ�����ݵļ���
		[4, 3, -2, -7, 8, 2, 3, 1]
		[4, -3, -2, -7, 8, 2, 3, 1]
		[4, -3, -2, -7, 8, 2, -3, 1]
		[4, -3, -2, -7, 8, 2, -3, -1]
		[4, -3, -2, -7, 8, 2, -3, -1]
		[4, -3, -2, -7, 8, 2, -3, -1]
		[-4, -3, -2, -7, 8, 2, -3, -1]
		*/
		//�������������ĵ��������������ȻΪ������֤�� 5, 6 û�г���

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

		//��������ÿ�γ��֣���һ�����鳤�ȣ����ȶ���ֵ����������鳤�Ȼ�С�ľ���û���ֹ���
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

