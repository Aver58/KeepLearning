#include "Global.h"

static void Test() {
	int head[8] = { 2,3,4,5,6,7,8,1 };
	BubbleSort(head);
}


void Swap(int array[], int i, int j)
{
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

// 1. 冒泡排序 -- 效率不高，适合小数据排序
// 平均时间复杂度：O(n^2)
// 空间复杂度：O(1)
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
			Swap(nums, i, j);
			if (nums[j] < nums[i])
			{
				int temp = nums[j];
				nums[j] = nums[i];
				nums[i] = temp;
			}
		}
	}
}

// 2. 插入排序
  
void InsertSort(int nums[])
{

}
