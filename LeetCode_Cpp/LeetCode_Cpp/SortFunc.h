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

// 1. ð������ -- Ч�ʲ��ߣ��ʺ�С��������
// ƽ��ʱ�临�Ӷȣ�O(n^2)
// �ռ临�Ӷȣ�O(1)
// �������������ȶԴ�С������Ƶ�����ȥ
void BubbleSort(int nums[])
{
	int len = sizeof(nums);
	// ���������ѡ��Ԫ��
	for (int i = 0; i < len; i++)
	{
		// �ڲ���������ѡ��Ԫ�رȶԴ�С
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

// 2. ��������
  
void InsertSort(int nums[])
{

}
