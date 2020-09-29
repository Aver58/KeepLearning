// ������16����ֵ�������η�
// ��Ŀ��ʵ�ֺ���double Power(double base, int exponent)����base��exponent
// �η�������ʹ�ÿ⺯����ͬʱ����Ҫ���Ǵ������⡣

#pragma once
#include <iostream>

class _16_Power
{
	bool equal(double num1, double num2)
	{
		if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
			return true;
		else
			return false;
	}

	//��ָ����: a��r���ݵĵ�����
	double Power(double base, int exponent)
	{

		if (equal(base, 0.0) && exponent < 0)
		{
			return 0.0;
		}

		unsigned int absExponent = (unsigned int)(exponent);
		if (exponent < 0)
			absExponent = (unsigned int)(-exponent);

		double result = PowerWithUnsignedExponent(base, absExponent);
		if (exponent < 0)
			result = 1.0 / result;

		return result;
	}

	/*
	double PowerWithUnsignedExponent(double base, unsigned int exponent)
	{
		double result = 1.0;
	
		for (int i = 1; i <= exponent; ++i)
			result *= base;
	
		return result;
	}
	*/
	// �޷���ָ����
	double PowerWithUnsignedExponent(double base, unsigned int exponent)
	{
		if (exponent == 0)
			return 1;
		if (exponent == 1)
			return base;

		double result = PowerWithUnsignedExponent(base, exponent >> 1);
		result *= result;
		if ((exponent & 0x1) == 1)
			result *= base;

		return result;
	}

	// ====================���Դ���====================
	void Test(const char* testName, double base, int exponent, double expectedResult, bool expectedFlag)
	{
		double result = Power(base, exponent);
		if (equal(result, expectedResult))
			std::cout << testName << " passed" << std::endl;
		else
			std::cout << testName << " FAILED" << std::endl;
	}
public:
	int main()
	{
		// ������ָ����Ϊ����
		Test("Test1", 2, 3, 8, false);

		// ����Ϊ������ָ��Ϊ����
		Test("Test2", -2, 3, -8, false);

		// ָ��Ϊ����
		Test("Test3", 2, -3, 0.125, false);

		// ָ��Ϊ0
		Test("Test4", 2, 0, 1, false);

		// ������ָ����Ϊ0
		Test("Test5", 0, 0, 1, false);

		// ����Ϊ0��ָ��Ϊ����
		Test("Test6", 0, 4, 0, false);

		// ����Ϊ0��ָ��Ϊ����
		Test("Test7", 0, -4, 0, true);

		return 0;
	}
};