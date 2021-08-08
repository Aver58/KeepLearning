
// 面试题15：二进制中1的个数
// 题目：请实现一个函数，输入一个整数，输出该数二进制表示中1的个数。例如
// 把9表示成二进制是1001，有2位是1。因此如果输入9，该函数输出2。

#pragma once
#include <cstdio>

class _15_NumberOf1InBinary
{
    // 方法1：遍历逐位比较是否是1，比完左移一位
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

    // 方法2：经验模型
    // 以1100为例：1100 - 1 = 1011；
    // 1011&1100 = 1000相当于把最右的1去掉，
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
    // ====================测试代码====================
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
        // 输入0，期待的输出是0
        Test(0, 0);

        // 输入1，期待的输出是1
        Test(1, 1);

        // 输入10，期待的输出是2
        Test(10, 2);

        // 输入0x7FFFFFFF，期待的输出是31
        Test(0x7FFFFFFF, 31);

        // 输入0xFFFFFFFF（负数），期待的输出是32
        Test(0xFFFFFFFF, 32);

        // 输入0x80000000（负数），期待的输出是1
        Test(0x80000000, 1);

        return 0;
    }
};