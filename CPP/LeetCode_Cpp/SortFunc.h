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
void BubbleSort(int nums[],int len)
{
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
void InsertSort(int nums[], int len)
{
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
void SelectionSort(int nums[], int len)
{
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

// 4. 快速排序
// 快速排序（Quicksort）是对冒泡排序的一种改进。
// 分治法，找一个基准值，然后双指针遍历，
// 把小的移到基准值的左边，大的右边，然后递归基准值左边和右边
// 平均时间复杂度：O(Logn)
// 空间复杂度：O(1)
// 稳定性：不稳定
int partition(int nums[],int left,int right)
{

	int pivot = nums[right];//选择最后一个元素作为比较元素
	// 双指针，i为快指针，j为慢指针
	int j = left;
	for (int i = left; i < right - 1; i++) // 注意right - 1,否则越界
	{
		// 在右边找比基准值小的
		// 在左边找比基准值大的
		if (nums[i] <= pivot)
			Swap(nums, i, j++);
	}
	// 基准值放到中间
	Swap(nums, j, right);
	return j;
}

void QuickSort(int nums[], int left, int right)
{
	if (left < right)
	{
		int pivot = partition(nums, left, right);//分成左右两半，一半不大于A[r], 一半不小于A[r]
		QuickSort(nums, left, pivot - 1);// 递归左边
		QuickSort(nums, pivot + 1, right);// 递归右边
	}
}

//5. 归并排序 
//分治法，递归拆分子序列，排序完再塞入原数组
// 平均时间复杂度均为O(nlogn)
// 空间复杂度：O(n)
// 稳定性：稳定
//https://www.cnblogs.com/chengxiao/p/6194356.html
//https://www.runoob.com/w3cnote/merge-sort.html  菜鸟教程

//将有二个有序数列a[first...mid]和a[mid...last]合并。
template<typename T>
void _MergeArray(T* nums, int left,int mid, int right) {
	// 左半段： [left,mid) 
	// 右半段： [mid + 1,right)
	// 都是有序的
	int i = left;
	int j = mid + 1; 

	int length = right - left;
	T* temp = new T[length];

	//临时数组指针k : 表明从什么位置开始修改数组
	int k = 0;
	while (k <= length)
	{
		//总共就3种情况：
		if (i > mid)
		{
			//①左边处理完了，把已排序的右边填入数组
			temp[k++] = nums[j++];
		}
		else if (j > right)
		{
			//②右边处理完了，把已排序的左边填入数组
			temp[k++] = nums[i++];
		}
		else
		{
			//③双指针比对大小，小的填入数组
			temp[k++] = nums[i] < nums[j] ? nums[i++]: nums[j++];
		}
	}

	// 将temp塞入数组的[left,right)位置
	k = 0;
	while (left <= right)
		nums[left++] = temp[k++];
}

template<typename T>
void MergeSort(T* nums,int left, int right) {
	if (left < right)
	{
		int mid = left + (right - left) / 2;	//避免int溢出
		MergeSort(nums, left, mid);				//对左边进行排序
		MergeSort(nums, mid + 1, right);		//对右边进行排序
		_MergeArray(nums, left, mid, right);	//把排序好的数据合并
	}
}

//6. 桶排序
//遍历一遍把出现的次数用map记录下来，然后遍历输出
void BucketSort(int nums[], int len) {
	map<int, int> map1;
	for (size_t i = 0; i < len; i++)
	{
		if (map1.find(nums[i])!=map1.end())
		{
			map1[nums[i]] += 1;
		}
		else
		{
			map1[nums[i]] = 1;
		}
	}

	int i = 0;
	for(auto item : map1)
	{
		if (item.second !=0)
		{
			while (item.second > 0)
			{
				nums[i++] = item.first;
				item.second--;
			}
		}
	}
}

//7. 希尔排序
void ShellSort(int nums[], int len) {
	int d = len;
	while (d > 1)
	{
		// 分组跨度：逐步折半
		d = d / 2;
		for (int x = 0; x < d; x++)
		{
			// 对每组元素进行排序。任何一种排序都可以，这边用插入排序
			for (int i = x + d; i < len; i+=d)
			{
				int temp = nums[i];
				int j = i - d;
				while (temp < nums[j] && j >= 0)
				{
					nums[j + d] = nums[j];
					j-=d;
				}
				nums[j + d] = temp;
			}
		}
	}
}

static void SortTest() {
	int head[8] = {2,3,4,6,8,7,0,1};
	//vector<int> head1 = vector<int>{ 2,3,4,5,8,7,0};
	//MergeSort(head,0,7);
	//BucketSort(head,8);
	ShellSort(head,8);

	int* head2 = head;

	//merge_sort(head,6);
	//Dump(head1, GetArrayLen(head1));
	//int i = 0;
	for (size_t i = 0; i < 8; i++)
	{
		cout << *head2++;
	}
}

