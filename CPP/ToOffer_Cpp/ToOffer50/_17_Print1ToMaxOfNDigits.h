// 面试题17：打印1到最大的n位数
// 题目：输入数字n，按顺序打印出从1最大的n位十进制数。比如输入3，则
// 打印出1、2、3一直到最大的3位数即999。

#pragma once
#include <cstdio>
#include <memory>
#include <cstring>

class _17_Print1ToMaxOfNDigits
{
	// 方法一、大数问题:字符串模拟加法
	void Print1ToMaxOfNDigits_1(int n)
	{
		if (n <= 0)
			return;
		char* number = new char[n + 1];
		memset(number, '0', n);
		number[n] = '\0';

		while (!Increment(number))
		{
			PrintNumber(number);
		}

		delete[]number;
	}

	// 字符串number表示一个数字，在 number上增加1
	// 如果做加法溢出，则返回true；否则为false
	bool Increment(char* number)
	{
		int nSum = 0;
		bool bOverFlow = false;
		int nTakeOver = 0;
		int nLength = strlen(number);
		for (int i = nLength - 1; i >= 0; i--)
		{
			nSum = number[i] - '0' + nTakeOver;
			// 加法
			if (i == nLength - 1)
				nSum++;

			if (nSum >= 10)
			{
				// 进位
				if (i == 0)
				{
					// 最后一位还进位就溢出了
					bOverFlow = true;
				}
				else
				{
					nTakeOver = 1;
					number[i] = '0';
				}
			}
			else
			{
				// 没进位，终止
				number[i] = '0' + nSum;
				break;
			}
		}
		return bOverFlow;
	}

	// ====================方法二：递归====================
	void Print1ToMaxOfNDigits_2(int n)
	{
		if (n <= 0)
			return;
		
		char* number = new char[n + 1];
		number[n] = '\0';

		for (int i = 0; i < 10; ++i) 
		{
			number[0] = i + '0';
			Print1ToMaxOfNDigitsRecursively(number, n, 0);
		}

		delete[] number;
	}

	void Print1ToMaxOfNDigitsRecursively(char* number,int length, int index)
	{
		if (index == length - 1)
		{
			PrintNumber(number);
			return;
		}

		for (int i = 0; i < 10; ++i)
		{
			number[index + 1] = i + '0';
			Print1ToMaxOfNDigitsRecursively(number, length, index + 1);
		}
	}

	// ====================公共函数====================
	// 字符串number表示一个数字，数字有若干个0开头
	// 打印出这个数字，并忽略开头的0
	void PrintNumber(char* number)
	{
		bool isBeginning0 = true;
		int nLength = strlen(number);

		for (int i = 0; i < nLength; ++i)
		{
			if (isBeginning0 && number[i] != '0')
				isBeginning0 = false;

			if (!isBeginning0)
			{
				printf("%c", number[i]);
			}
		}

		printf("\t");
	}

	// ====================测试代码====================
	void Test(int n)
	{
		printf("Test for %d begins:\n", n);

		Print1ToMaxOfNDigits_1(n);
		Print1ToMaxOfNDigits_2(n);

		printf("\nTest for %d ends.\n", n);
	}
public:
	int main()
	{
		Test(1);
		Test(2);
		Test(3);
		Test(0);
		Test(-1);

		return 0;
	}
};

