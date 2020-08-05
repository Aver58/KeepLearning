#pragma once
#include <iostream>
using namespace std;

class _03_01_DuplicationInArray
{
// ������3��һ�����ҳ��������ظ�������
//	��Ŀ����һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ�
//	������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�
//	Ҳ��֪��ÿ�������ظ��˼��Ρ����ҳ�����������һ���ظ������֡�
//	���磬������볤��Ϊ7������{2, 3, 1, 0, 2, 5, 3}��
//	��ô��Ӧ��������ظ�������2����3��
public:
	void Test() {
		int numbers[] = { 2, 3, 1, 0, 2, 5, 3 };
		int duplication = 1;
		int* pDunplication = &duplication;
		cout << duplicate(numbers, 7, pDunplication);
	}
	bool duplicate(int numbers[], int length, int* duplication)
	{
		//1. ����
		//2. map
		//3. �±�,������Ը�����Ļ������������ֶ���0��n-1�ķ�Χ�ڡ�����������ָ���±ꡣ
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
				// ����λ��
				int temp = numbers[num];
				numbers[num] = num;
				numbers[i] = temp;
			}
		}

		return false;
	}
};

