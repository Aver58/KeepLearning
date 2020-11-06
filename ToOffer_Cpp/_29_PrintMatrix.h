// 面试题29：顺时针打印矩阵
// 题目：输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

//输入：
//1  2  3  4
//5  6  7  8
//9  10 11 12 
//13 14 15 16
//输出：
//==> 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
#pragma once
#include <stdio.h>
class _29_PrintMatrix
{
	void printNumber(int number)
	{
		printf("%d\t", number);
	}

	// 转化成打印一圈又一圈的圆
	void PrintMatrixClockwisely(int** numbers, int columns, int rows)
	{
		if (numbers == nullptr || columns <= 0 || rows <= 0)
			return;

		int start = 0;
		while (start * 2 <= columns && start * 2 <= rows)
		{
			PrintMatrixInCircle(numbers, columns, rows, start);
			start++;
		}
	}


	void PrintMatrixInCircle(int** numbers, int columns, int rows, int start)
	{
		int startX = start;
		int endX = columns - startX - 1;
		int startY = start;
		int endY = rows - startY - 1;
		// 从左上到右上打印
		for (int column = startX; column <= endX; column++)
		{
			printNumber(numbers[startY][column]);
		}
		// 从右上到右下打印 == 注意可能只有一行
		if (startY < endY)
		{
			for (int row = startY; row <= endY; row++)
			{
				printNumber(numbers[row][endY]);
			}
		}
		// 从右下到左下打印
		if (startX < endX && startY < endY)
		{
			for (int column = endX; column >= startX; column--)
			{
				printNumber(numbers[endY][column]);
			}
		}
		
		// 从左下到左上打印
		if (startX < endX && startY < endY - 1)
		{
			for (int row = endX; row >= startX; row--)
			{
				printNumber(numbers[row][startX]);
			}
		}
	}

    // ====================测试代码====================
    void Test(int columns, int rows)
    {
        printf("Test Begin: %d columns, %d rows.\n", columns, rows);

        if (columns < 1 || rows < 1)
            return;

        int** numbers = new int* [rows];
        for (int i = 0; i < rows; ++i)
        {
            numbers[i] = new int[columns];
            for (int j = 0; j < columns; ++j)
            {
                numbers[i][j] = i * columns + j + 1;
            }
        }

        PrintMatrixClockwisely(numbers, columns, rows);
        printf("\n");

        for (int i = 0; i < rows; ++i)
            delete[](int*)numbers[i];

        delete[] numbers;
    }

    int main(int argc, char* argv[])
    {
        /*
        1
        */
        Test(1, 1);

        /*
        1    2
        3    4
        */
        Test(2, 2);

        /*
        1    2    3    4
        5    6    7    8
        9    10   11   12
        13   14   15   16
        */
        Test(4, 4);

        /*
        1    2    3    4    5
        6    7    8    9    10
        11   12   13   14   15
        16   17   18   19   20
        21   22   23   24   25
        */
        Test(5, 5);

        /*
        1
        2
        3
        4
        5
        */
        Test(1, 5);

        /*
        1    2
        3    4
        5    6
        7    8
        9    10
        */
        Test(2, 5);

        /*
        1    2    3
        4    5    6
        7    8    9
        10   11   12
        13   14   15
        */
        Test(3, 5);

        /*
        1    2    3    4
        5    6    7    8
        9    10   11   12
        13   14   15   16
        17   18   19   20
        */
        Test(4, 5);

        /*
        1    2    3    4    5
        */
        Test(5, 1);

        /*
        1    2    3    4    5
        6    7    8    9    10
        */
        Test(5, 2);

        /*
        1    2    3    4    5
        6    7    8    9    10
        11   12   13   14    15
        */
        Test(5, 3);

        /*
        1    2    3    4    5
        6    7    8    9    10
        11   12   13   14   15
        16   17   18   19   20
        */
        Test(5, 4);

        return 0;
    }
};

