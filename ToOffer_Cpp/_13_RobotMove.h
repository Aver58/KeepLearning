// 面试题13：机器人的运动范围
// 题目：地上有一个m行n列的方格。一个机器人从坐标(0, 0)的格子开始移动，它
// 每一次可以向左、右、上、下移动一格，但不能进入行坐标和列坐标的数位之和
// 大于k的格子。例如，当k为18时，机器人能够进入方格(35, 37)，因为3+5+3+7=18。
// 但它不能进入方格(35, 38)，因为3+5+3+8=19。请问该机器人能够到达多少个格子？
#pragma once
#include <string>

class _13_RobotMove
{
	// 回溯法训练
	int movingCount(int threshold, int rows, int cols)
	{
		if (threshold <= 0 || rows < 1 || cols < 1)
			return 0;
		
		bool* visited = new bool[rows * cols];
		memset(visited, 0, rows * cols);
		int moveCount = movingCount(threshold, rows, cols, 0, 0, moveCount, visited);;
		
		delete[] visited;

		return moveCount;
	}
	
	// 数位之和
	int GetDigitSum(int num)
	{
		int sum = 0;
		int temp = num;
		while (temp / 10 > 10)
		{
			sum += temp % 10;
			temp /= 10;
		}
		return sum;
	}

	// 是否在阈值内
	bool IsInThreshold(int threshold, int row, int col)
	{
		return GetDigitSum(row) + GetDigitSum(col) <= threshold;
	}

	int movingCount(int threshold, int rows, int cols, int row, int col,int& moveCount, bool* visited)
	{
		int count = 0;
		if (row >= 0 && row < rows 
			&& col >=0 && col < cols
			&& !visited[row * cols + row]
			&& IsInThreshold(threshold,row,col))
		{
			moveCount++;
			visited[row * cols + row] = true;

			count = 1 + movingCount(threshold, rows, cols, row - 1, col, moveCount, visited)
				+ movingCount(threshold, rows, cols, row + 1, col, moveCount, visited)
				+ movingCount(threshold, rows, cols, row, col - 1, moveCount, visited)
				+ movingCount(threshold, rows, cols, row, col + 1, moveCount, visited);
		}
		return count;
	}


	// ====================测试代码====================
	void test(const char* testName, int threshold, int rows, int cols, int expected)
	{
		if (testName != nullptr)
			printf("%s begins: ", testName);

		if (movingCount(threshold, rows, cols) == expected)
			printf("Passed.\n");
		else
			printf("FAILED.\n");
	}

	// 方格多行多列
	void test1()
	{
		test("Test1", 5, 10, 10, 21);
	}

	// 方格多行多列
	void test2()
	{
		test("Test2", 15, 20, 20, 359);
	}

	// 方格只有一行，机器人只能到达部分方格
	void test3()
	{
		test("Test3", 10, 1, 100, 29);
	}

	// 方格只有一行，机器人能到达所有方格
	void test4()
	{
		test("Test4", 10, 1, 10, 10);
	}

	// 方格只有一列，机器人只能到达部分方格
	void test5()
	{
		test("Test5", 15, 100, 1, 79);
	}

	// 方格只有一列，机器人能到达所有方格
	void test6()
	{
		test("Test6", 15, 10, 1, 10);
	}

	// 方格只有一行一列
	void test7()
	{
		test("Test7", 15, 1, 1, 1);
	}

	// 方格只有一行一列
	void test8()
	{
		test("Test8", 0, 1, 1, 1);
	}

	// 机器人不能进入任意一个方格
	void test9()
	{
		test("Test9", -10, 10, 10, 0);
	}

	int main(int agrc, char* argv[])
	{
		test1();
		test2();
		test3();
		test4();
		test5();
		test6();
		test7();
		test8();
		test9();

		return 0;
	}
};