#pragma once
#include <iostream>
using namespace std;

class _03_01_DuplicationInArray
{
// 面试题3（一）：找出数组中重复的数字
//	题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。
//	数组中某些数字是重复的，但不知道有几个数字重复了，
//	也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
//	例如，如果输入长度为7的数组{2, 3, 1, 0, 2, 5, 3}，
//	那么对应的输出是重复的数字2或者3。
public:
	void Test() {
		int numbers[] = { 2, 3, 1, 0, 2, 5, 3 };
		int duplication = 1;
		int* pDunplication = &duplication;
		cout << duplicate(numbers, 7, pDunplication);
	}
	bool duplicate(int numbers[], int length, int* duplication)
	{
		//1. 排序
		//2. map
		//3. 下标,如果可以改数组的话，【所有数字都在0到n-1的范围内】把数字塞回指定下标。
		if (length <= 0|| numbers== nullptr)
			return;

		for (int i = 0; i < length; ++i)
		{
			if (numbers[i] < 0 || numbers[i] > length - 1)
				return false;
		}

		for (int i = 0; i < length - 1; i++)
		{	
			while (numbers[i] != i)
			{
				int num = numbers[i];
				if (numbers[num] == num)
				{
					*duplication = num;
					return false;
				}
				// 交换位置
				int temp = numbers[num];
				numbers[num] = num;
				numbers[i] = temp;
			}
		}

		return false;
	}
};

