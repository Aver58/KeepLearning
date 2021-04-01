#pragma once

// ������10��쳲���������
// ��Ŀ��дһ������������n����쳲�������Fibonacci�����еĵ�n�

class _10_Fibonacci
{
	// ====================����1���ݹ�====================
	long long Fibonacci_Solution1(unsigned int n)
	{
		if (n <= 0)
			return 0;

		if (n == 1)
			return 1;

		return Fibonacci_Solution1(n - 1) + Fibonacci_Solution1(n - 2);
	}

	// ====================����2��ѭ��====================
    long long Fibonacci_Solution2(unsigned n)
    {
        int result[2] = { 0, 1 };
        if (n < 2)
            return result[n];

        long long  fibNMinusOne = 1;
        long long  fibNMinusTwo = 0;
        long long  fibN = 0;
        for (unsigned int i = 2; i <= n; ++i)
        {
            fibN = fibNMinusOne + fibNMinusTwo;

            fibNMinusTwo = fibNMinusOne;
            fibNMinusOne = fibN;
        }

        return fibN;
    }
    // ====================����3�����ھ���˷�====================


    // ====================���Դ���====================
    void Test(int n, int expected)
    {
        if (Fibonacci_Solution1(n) == expected)
            printf("Test for %d in solution1 passed.\n", n);
        else
            printf("Test for %d in solution1 failed.\n", n);

        if (Fibonacci_Solution2(n) == expected)
            printf("Test for %d in solution2 passed.\n", n);
        else
            printf("Test for %d in solution2 failed.\n", n);

        //if (Fibonacci_Solution3(n) == expected)
        //    printf("Test for %d in solution3 passed.\n", n);
        //else
        //    printf("Test for %d in solution3 failed.\n", n);
    }
};

