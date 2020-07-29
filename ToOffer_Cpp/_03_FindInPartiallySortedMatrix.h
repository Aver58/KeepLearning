#pragma once
// ��ά�����еĲ���
// ��Ŀ����һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������
// ÿһ�ж����մ��ϵ��µ�����˳������
// �����һ������������������һ����ά�����һ���������ж��������Ƿ��и�������
using namespace std;
#include <iostream>

class _03_FindInPartiallySortedMatrix
{
public:
	void Test() {
		int matrix[4][4] = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
		cout << IsInMatrix((int*)matrix, 4, 4, 5);
	}
	bool IsInMatrix(int* matrix,int rows,int columns,int number) 
	{
		bool found = false;
		if (matrix != nullptr && rows > 0 && columns > 0)
		{
			int row = 0;
			int column = columns - 1;
			while (row < rows && column >= 0)
			{
				if (number == matrix[row * columns + column])
				{
					found = true;
					break;
				}
				else
				{
					if (number > matrix[row * column + column])
					{
						row++;
					}
					else
					{
						column--;
					}
				}
			}
		}
		return found;
	}
};