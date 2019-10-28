#include "Global.h"

/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/
#pragma once
class _283_MoveZeroes
{
public:
	static void Test() {
		vector<int> Input;//����һ�������洢���� int
		Input.push_back(0);
		Input.push_back(1);
		Input.push_back(0);
		Input.push_back(3);
		Input.push_back(12);
		moveZeroes(Input);
	}

	//&nums���ص���nums�ڴ��ַ
	//*numsȡ������nums����
	static void moveZeroes(vector<int>& nums) {
		// 1. ����һ������vector<int> ansʵ��
		//int n = nums.size();
		//// Count the zeroes
		//int zeroeCount = 0;
		//for (int i = 0; i < n; i++) {
		//	zeroeCount += (nums[i] == 0);
		//}

		//// Make all the non-zero elements retain their original order.
		//vector<int> ans;
		//for (int i = 0; i < n; i++) {
		//	if (nums[i] != 0) {
		//		ans.push_back(nums[i]);
		//	}
		//}

		//// Move all zeroes to the end
		//while (zeroeCount--) {
		//	ans.push_back(0);
		//}

		//// ���ϲ�
		//for (int i = 0; i < n; i++) {
		//	nums[i] = ans[i];
		//}

		// 2. ˫ָ��
		// ����һ�飬��0��Ų��lastPointerλ�ô�������ں���λ������0
		//int lastPointer = 0;
		//for (int i = 0; i < nums.size(); i++)
		//{
		//	if (nums[i] != 0)
		//	{
		//		nums[lastPointer++] = nums[i];
		//	}
		//}
		//for (int i = lastPointer; i < nums.size(); i++) {
		//	nums[i] = 0;
		//}

		// 3. ���� 12ms 99.28%
		int lastPointer = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] != 0)
			{
				int temp = nums[lastPointer];
				nums[lastPointer++] = nums[i];
				nums[i] = temp;
			}
		}
	}
};

