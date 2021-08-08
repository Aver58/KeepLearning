
// ������15����������1�ĸ���
// ��Ŀ����ʵ��һ������������һ��������������������Ʊ�ʾ��1�ĸ���������
// ��9��ʾ�ɶ�������1001����2λ��1������������9���ú������2��

#pragma once
#include <cstdio>

class _15_NumberOf1InBinary
{
    // ����1��������λ�Ƚ��Ƿ���1����������һλ
    int NumberOf1_Solution1(int n)
    {
        int count = 0;
        unsigned int flag = 1;
        while (flag)
        {
            if (n & flag)
                count++;

            flag = flag << 1;
        }

        return count;
    }

    // ����2������ģ��
    // ��1100Ϊ����1100 - 1 = 1011��
    // 1011&1100 = 1000�൱�ڰ����ҵ�1ȥ����
    int NumberOf1_Solution2(int n)
    {
        int count = 0;
        
        while (n)
        {
            ++count;
            n = (n - 1) & n;
        }

        return count;
    }
    // ====================���Դ���====================
    void Test(int number, unsigned int expected)
    {
        int actual = NumberOf1_Solution1(number);
        if (actual == expected)
            printf("Solution1: Test for %d passed.actual = %d \n", number, actual);
        else
            printf("Solution1: Test for %d failed.actual = %d \n", number, actual);

        actual = NumberOf1_Solution2(number);
        if (actual == expected)
            printf("Solution2: Test for %d passed.actual = %d \n", number, actual);
        else
            printf("Solution2: Test for %d failed.actual = %d \n", number, actual);

        printf("\n");
    }

public:
    int main()
    {
        // ����0���ڴ��������0
        Test(0, 0);

        // ����1���ڴ��������1
        Test(1, 1);

        // ����10���ڴ��������2
        Test(10, 2);

        // ����0x7FFFFFFF���ڴ��������31
        Test(0x7FFFFFFF, 31);

        // ����0xFFFFFFFF�����������ڴ��������32
        Test(0xFFFFFFFF, 32);

        // ����0x80000000�����������ڴ��������1
        Test(0x80000000, 1);

        return 0;
    }
};