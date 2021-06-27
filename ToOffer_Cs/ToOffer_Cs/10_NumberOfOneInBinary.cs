using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Algorithm.ToOffer
{

    /*
     二进制中1的个数
     input：9
     output：2
         */
    public class _10_NumberOfOneInBinary
    {
        /// <summary>
        /// 这个算法没有考虑到负数的情况，可能会死循环
        /// </summary>
        /// <param name="n"></param>
        /// <returns></returns>
        public static int NumberOfOneInBinaryRightMove(int n)
        {
            int numOfOne = 0;
            while (n > 0)
            {
                //判断int型变量a是奇数还是偶数
                //a & 1 = 0 偶数
                //a & 1 = 1 奇数
                if ((n & 1) == 1)
                    numOfOne++;
                //移位效率比除法不知道高到哪里去了
                n = n >> 1;
            }
            return numOfOne;
        }


        public static int NumberOfOneInBinaryLeftMove(int n)
        {
            int numOfOne = 0;
            //逐位比较是否为1
            for (int i = 0; i < n; i<<=1)
            {
                if ((n & i) > 0)
                    numOfOne += 1;
            }
            //int flag = 1;
            //while (flag < n)
            //{
            //    //逐位比较是否为1
            //    if ((n & flag) > 0)
            //        numOf1++;
            //    flag = flag << 1;
            //}
            return numOfOne;
        }

        /// <summary>
        /// 不断清除n的二进制表示中最右边的1，同时累加计数器，直至n为0
        /// 
        /// 为什么n &= (n – 1)能清除最右边的1呢？因为从二进制的角度讲，
        /// n相当于在n - 1的最低位加上1。举个例子，8（1000）= 7（0111）+ 1（0001），
        /// 所以8 & 7 = （1000）&（0111）= 0（0000），清除了8最右边的1（其实就是最高位的1，
        /// 因为8的二进制中只有一个1）。再比如7（0111）= 6（0110）+ 1（0001），
        /// 所以7 & 6 = （0111）&（0110）= 6（0110），
        /// 清除了7的二进制表示中最右边的1（也就是最低位的1）。
        /// </summary>
        /// <param name="n"></param>
        /// <returns></returns>
        public static int NumberOfOneInBinary(int n)
        {
            int numOfOne = 0;
            for (; n>0; numOfOne++)
            {
                //清除最低位的1
                n &= (n - 1);
            }
            return numOfOne;
        }

        /*
         1. 用一个语句判断一个整数是不是2的整数次方。（即 除了最高位为1，其他都为0）
            (n&(n-1)) == 0
             */


        /*
         2. 输入2个整数m和n，需要改变m的二进制多少位才能变成n
             */
        public static int CountOfChangeM2N(int m,int n)
        {
            int numOfOne = 0;
            //异或运算：位不同的为1
            int value = m ^ n;
            //然后求出1的个数
            for (; value > 0; numOfOne++)
            {
                value &= (value - 1);
            }
            return numOfOne;
        }


        //class Program
        //{
        //    static void Main()
        //    {
        //        Console.WriteLine(NumberOfOneInBinary(9));

        //        Console.ReadLine();
        //    }
        //}

    }
 
}
