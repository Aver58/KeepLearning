// ������13�������˵��˶���Χ
// ��Ŀ��������һ��m��n�еķ���һ�������˴�����(0, 0)�ĸ��ӿ�ʼ�ƶ�����
// ÿһ�ο��������ҡ��ϡ����ƶ�һ�񣬵����ܽ�������������������λ֮��
// ����k�ĸ��ӡ����磬��kΪ18ʱ���������ܹ����뷽��(35, 37)����Ϊ3+5+3+7=18��
// �������ܽ��뷽��(35, 38)����Ϊ3+5+3+8=19�����ʸû������ܹ�������ٸ����ӣ�
#pragma once
#include <string>

class _13_RobotMove
{
	// ���ݷ�ѵ��
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
	
	// ��λ֮��
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

	// �Ƿ�����ֵ��
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


	// ====================���Դ���====================
	void test(const char* testName, int threshold, int rows, int cols, int expected)
	{
		if (testName != nullptr)
			printf("%s begins: ", testName);

		if (movingCount(threshold, rows, cols) == expected)
			printf("Passed.\n");
		else
			printf("FAILED.\n");
	}

	// ������ж���
	void test1()
	{
		test("Test1", 5, 10, 10, 21);
	}

	// ������ж���
	void test2()
	{
		test("Test2", 15, 20, 20, 359);
	}

	// ����ֻ��һ�У�������ֻ�ܵ��ﲿ�ַ���
	void test3()
	{
		test("Test3", 10, 1, 100, 29);
	}

	// ����ֻ��һ�У��������ܵ������з���
	void test4()
	{
		test("Test4", 10, 1, 10, 10);
	}

	// ����ֻ��һ�У�������ֻ�ܵ��ﲿ�ַ���
	void test5()
	{
		test("Test5", 15, 100, 1, 79);
	}

	// ����ֻ��һ�У��������ܵ������з���
	void test6()
	{
		test("Test6", 15, 10, 1, 10);
	}

	// ����ֻ��һ��һ��
	void test7()
	{
		test("Test7", 15, 1, 1, 1);
	}

	// ����ֻ��һ��һ��
	void test8()
	{
		test("Test8", 0, 1, 1, 1);
	}

	// �����˲��ܽ�������һ������
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