using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Algorithm.ToOffer
{
    class _09_FibonacciArray
    {
        /*
         写一个函数，输入n,求斐波那契数列的第n项；

         应用：1. 一只青蛙 一次可以跳一个台阶，也可以跳2个台阶，
                  求该青蛙跳上n级台阶总共几种跳法
                  f(n) = f(n-1) + f(n-2)
               2. 请问用8个2*1的矩形覆盖一个2*8的大矩形，有几种盖法？
                  f(8) = f(7){竖着放}+f(6){横着放}
         */

        public int Fibonacci(int n)
        {
            if (n==0)
            {
                return 0;
            }
            if (n==1)
            {
                return 1;
            }
            return n + Fibonacci(n-1);
        }

        public int Fibonacci_NoRecursive(int n)
        {
            int[] result = new int[2] {0,1};
            if (n<2)
                return result[n];

            int fib1 = 0;
            int fib2 = 1;
            int fibN = 0;
            for (int i = 2; i < n; i++)
            {
                fibN = fib1 + fib2;

                fib2 = fib1;
                fib1 = fibN;
            }
            return fibN;
        }

        /*
            在Excel 中，A表示第一列，B第二列，……，Z表示第26列，AA表示27列，AB第28列
            实现一个函数，输入字母编码，输出列号。
            十进制转换成26进制
            input：AA
            output：27
        */
        public static void TwentySixDecode(string code)
        {
            if (string.IsNullOrEmpty(code))
                throw new Exception("IsNullOrEmpty");

            int colums = 0,exp = 0;
            for (int i = code.Length - 1; i < 0; i--)
            {
                if (code[i] < 65|| code[i] > 90)
                {
                    throw new Exception("Invalid Input!");
                }
                int colum = code[i] - 'A' + 1;
                colums += colum * (int)Math.Pow(26, exp);
                exp++;
            }
        }
    }
}
