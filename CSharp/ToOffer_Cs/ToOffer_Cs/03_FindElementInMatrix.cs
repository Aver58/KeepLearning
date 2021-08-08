using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Algorithm.ToOffer
{
    class _FindElementInMatrix
    {
        /*
         数组、字符串、链表、树、栈和队列

         数组、字符串，基础,分别存储
         链表和树，高频调用指针，注意代码的鲁棒性（Robust）
         栈，递归
         队列，广度优先遍历算法
         */

        //面试题3 二维数组中的查找
        //题目：在一个二维数组中，每行都是按照从左到右递增顺序排列，
        //每列都是按照从上到下递增顺序排列。
        //完成一个函数，实现查找二维数组中是否还有输入的整数。
        //input：int[,],n
        //output:true
        public static bool FindElementInMatrix(int[,] matrix,int n)
        {
            if (matrix == null)
            {
                return false;
            }

            //获取 System.Array 的秩（维数）（行数）
            int rows = (int)matrix.GetLongLength(0); 
            //获取第一维度的列数
            int columns = matrix.Rank;
            if (rows <= 0 || columns <= 0)
            {
                return false;
            }

            bool isHave = false;
            //左上角开始访问，有点类似中点的感觉
            int row = 0, column = columns-1;
            //数组越界一万次了，巩固一下多维数组的访问再来
            while (column >= 0 && row < rows)
            {
                if (n == matrix[row,column])
                {
                    isHave = true;
                    break;
                }
                else if (n > matrix[row, column])
                {
                    ++row;
                }
                else
                {
                    --column;
                }
            }
            return isHave;
        }

        ////编写测试用例
        //class Program
        //{
        //    static void Main()
        //    {
        //        //1. 可查到的数
        //        Console.WriteLine(FindElementInMatrix(new int[,] { { 1, 3 }, { 2, 5 }, { 3, 6 } }, 5) );
        //        //2.查不到的数
        //        Console.WriteLine(FindElementInMatrix(new int[,] { { 1, 3 }, { 2, 5 }, { 3, 6 } }, 4));
        //        //3. 输入空数组
        //        Console.WriteLine(FindElementInMatrix(null, 4));

        //        Console.ReadLine();
        //    }
        //}
    }
}
