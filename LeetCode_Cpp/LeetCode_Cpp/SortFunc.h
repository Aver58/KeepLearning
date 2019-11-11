#include "Global.h"

/// 交换数组两个值
void Swap(int array[], int i, int j)
{
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

// 1. 冒泡排序 (按照从小到大的顺序排序) 效率不高，适合小数据排序
// 平均时间复杂度：O(n^2)
// 空间复杂度：O(1)
// 稳定性：稳定

// 两层遍历，逐个比对大小，大的移到后面去
void BubbleSort(int nums[])
{
	int len = sizeof(nums);
	// 外层遍历逐个选中元素
	for (int i = 0; i < len; i++)
	{
		// 内层遍历逐个与选中元素比对大小
		for (int j = i + 1; j < len; j++)
		{
			if (nums[j] < nums[i])
			{
				Swap(nums, i, j);
			}
		}
	}
}

// 2. 插入排序 (按照从小到大的顺序排序)
// 平均时间复杂度：O(n^2)
// 空间复杂度：O(1)
// 稳定性：稳定

// 两次遍历，直接插入到指定位置
void InsertSort(int nums[])
{
	int len = sizeof(nums);
	// 外层遍历逐个选中元素
	for (int i = 0; i < len; i++)
	{
		int target = nums[i];
		int j = i - 1;
		while ((j >= 0) && target < nums[j])
		{
			nums[j + 1] = nums[j];
			j--;
		}
		nums[j + 1] = target;
	}
}

// 3. 选择排序
// 平均时间复杂度：O(n^2)
// 空间复杂度：O(1)
// 稳定性：不稳定

//从数组中选出最小的数，放到已排序的数组末端
void SelectionSort(int nums[])
{
	int len = sizeof(nums);
	//cout << sizeof(nums);			// 8
	//cout << GetArrayLen(nums);	// 2 ??
	//数组在作为函数参数传递过程中，会退化成指针。这也是为什么指针作为参数传递时，经常要一个长度。
	for (int i = 0; i < len; i++)
	{
		int min = i;
		for (int j = i + 1; j < len; j++)
		{
			if (nums[j] < nums[min])
			{
				min = j;
			}
		}
		Swap(nums, i, min);
	}
}

//4. 快速排序
//快速排序（Quicksort）是对冒泡排序的一种改进。

static void SortTest() {
	int head[8] = { 2,3,4,5,6,7,8,1 };
	SelectionSort(head);
	Dump(head, GetArrayLen(head));
}

