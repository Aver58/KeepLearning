#pragma once
#include "SortBase.h"

// 1. ð������ (���մ�С�����˳������) Ч�ʲ��ߣ��ʺ�С��������
// ƽ��ʱ�临�Ӷȣ�O(n^2)
// �ռ临�Ӷȣ�O(1)
// �ȶ��ԣ��ȶ�

// �������������ȶԴ�С������Ƶ�����ȥ
void BubbleSort0(int nums[], int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (nums[j] < nums[i])
			{
				Swap(nums, i, j);
			}
		}
	}
}

//void BubbleSort(int nums[], int len)
//{
//
//}