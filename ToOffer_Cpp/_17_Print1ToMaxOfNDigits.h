// ������17����ӡ1������nλ��
// ��Ŀ����������n����˳���ӡ����1����nλʮ����������������3����
// ��ӡ��1��2��3һֱ������3λ����999��

#pragma once
#include <cstdio>
#include <memory>

class _17_Print1ToMaxOfNDigits
{
	// ��������:�ַ���ģ��ӷ�
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
};

