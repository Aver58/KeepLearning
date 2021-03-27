#pragma once
#include "SortBase.h"

// 1. 冒泡排序 (按照从小到大的顺序排序) 效率不高，适合小数据排序
// 平均时间复杂度：O(n^2)
// 空间复杂度：O(1)
// 稳定性：稳定

// 两层遍历，逐个比对大小，大的移到后面去
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