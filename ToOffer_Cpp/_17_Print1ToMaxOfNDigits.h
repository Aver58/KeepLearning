// ������17����ӡ1������nλ��
// ��Ŀ����������n����˳���ӡ����1����nλʮ����������������3����
// ��ӡ��1��2��3һֱ������3λ����999��

#pragma once
#include <cstdio>
#include <memory>

class _17_Print1ToMaxOfNDigits
{
	// ����һ����������:�ַ���ģ��ӷ�
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

	// �ַ���number��ʾһ�����֣��� number������1
	// ������ӷ�������򷵻�true������Ϊfalse
	bool Increment(char* number)
	{
		int nSum = 0;
		bool bOverFlow = false;
		int nTakeOver = 0;
		int nLength = strlen(number);
		for (int i = nLength - 1; i >= 0; i--)
		{
			nSum = number[i] - '0' + nTakeOver;
			// �ӷ�
			if (i == nLength - 1)
				nSum++;

			if (nSum >= 10)
			{
				// ��λ
				if (i == 0)
				{
					// ���һλ����λ�������
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
				// û��λ����ֹ
				number[i] = '0' + nSum;
				break;
			}
		}
		return bOverFlow;
	}

	// ====================���������ݹ�====================
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

	// ====================��������====================
	// �ַ���number��ʾһ�����֣����������ɸ�0��ͷ
	// ��ӡ��������֣������Կ�ͷ��0
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

	// ====================���Դ���====================
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

