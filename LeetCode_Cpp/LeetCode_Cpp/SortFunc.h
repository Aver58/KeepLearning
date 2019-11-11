#include "Global.h"

/// ������������ֵ
void Swap(int array[], int i, int j)
{
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

// 1. ð������ (���մ�С�����˳������) Ч�ʲ��ߣ��ʺ�С��������
// ƽ��ʱ�临�Ӷȣ�O(n^2)
// �ռ临�Ӷȣ�O(1)
// �ȶ��ԣ��ȶ�

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
			if (nums[j] < nums[i])
			{
				Swap(nums, i, j);
			}
		}
	}
}

// 2. �������� (���մ�С�����˳������)
// ƽ��ʱ�临�Ӷȣ�O(n^2)
// �ռ临�Ӷȣ�O(1)
// �ȶ��ԣ��ȶ�

// ���α�����ֱ�Ӳ��뵽ָ��λ��
void InsertSort(int nums[])
{
	int len = sizeof(nums);
	// ���������ѡ��Ԫ��
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

// 3. ѡ������
// ƽ��ʱ�临�Ӷȣ�O(n^2)
// �ռ临�Ӷȣ�O(1)
// �ȶ��ԣ����ȶ�

//��������ѡ����С�������ŵ������������ĩ��
void SelectionSort(int nums[])
{
	int len = sizeof(nums);
	//cout << sizeof(nums);			// 8
	//cout << GetArrayLen(nums);	// 2 ??
	//��������Ϊ�����������ݹ����У����˻���ָ�롣��Ҳ��Ϊʲôָ����Ϊ��������ʱ������Ҫһ�����ȡ�
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

//4. ��������
//��������Quicksort���Ƕ�ð�������һ�ָĽ���

static void SortTest() {
	int head[8] = { 2,3,4,5,6,7,8,1 };
	SelectionSort(head);
	Dump(head, GetArrayLen(head));
}

