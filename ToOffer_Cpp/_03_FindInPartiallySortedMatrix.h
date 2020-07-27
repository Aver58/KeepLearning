#pragma once
// 二维数组中的查找
// 题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，
// 每一列都按照从上到下递增的顺序排序。
// 请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
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
			int column = 0;
			while (row < rows && column < columns)
			{
				int index = columns - 1;
				if (number == matrix[row * column + index])
				{
					found = true;
					break;
				}
				else
				{
					if (number > matrix[row * column + index])
					{
						row++;
					}
					else
					{
						index--;
					}
				}
			}
		}
		return found;
	}
};