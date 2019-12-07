using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Algorithm.ToOffer
{
    class ReplaceBlank
    {
        /*
         面试题4：请实现一个函数，把字符串中的每个空格替换成"%20",
         input: We are friend!
         output:We%20are%20friend!
         */

        /// <summary>
        /// C# 写法
        /// </summary>
        /// <param name="s"></param>
        /// <returns></returns>
        public static string ReplaceAllBlank(string s)
        {
            if (String.IsNullOrEmpty(s))
            {
                return null;
            }

            char[] chars = s.ToCharArray();
            StringBuilder sb = new StringBuilder();
            int newLength = chars.Length;
            for (int i = 0; i < s.Length; i++)
            {
                if (chars[i] == ' ')
                {
                    sb.Append("%20");
                }
                else
                {
                    sb.Append(s[i]);
                }
            }
            return sb.ToString();
        }

        /// <summary>
        /// 神奇地后入 
        /// 写法：先顺序遍历，算出当前字符串长度和替换后的字符串长度，
        /// 然后将指针指向最后一个字符的位置，依次向前遍历，将当前字符串依次替换到新的空间内
        /// </summary>
        /// <param name="s"></param>
        /// <param name="length">length是字符数组string的总容量</param>
        /// <returns>输出字符</returns>
        public static char[] ReplaceAllBlank2(char[] s, int length)
        {
            if (String.IsNullOrEmpty(s.ToString()))
            {
                return null;
            }

            int originLength = 0, replaceLength = 0;
            for (int i = 0; i < s.Length; i++)
            {
                originLength++;
                if (s[i] == ' ')
                {
                    replaceLength += 3;
                }
                else
                {
                    replaceLength++;
                }
            }

            if (replaceLength > length) return null;

            var newChars = new char[replaceLength];
            int originLastPointer = originLength - 1;
            int newLastPointer = replaceLength - 1;
            //神奇地后入
            while (originLastPointer >= 0 && newLastPointer >= originLastPointer)
            {
                if (s[originLastPointer] == ' ')
                {
                    newChars[newLastPointer--] = '0';
                    newChars[newLastPointer--] = '2';
                    newChars[newLastPointer--] = '%';
                }
                else
                {
                    newChars[newLastPointer--] = s[originLastPointer];
                }
                originLastPointer--;
            }
            return newChars;
        }

        /*
        相关题目，有两个排序的数组A1和A2，内存在A1的末尾有足够多的空余空间容纳A2。
              请实现一个函数，把A2中的所有数字插入到A1中，并且所有的数字是排序的。
        */
        public static int[] InserA1ToA2AndSorted(int[] A1, int[] A2,int length1,int length2)
        {
            if (A1 == null)
            {
                return A2;
            }
            else if(A2 == null)
            {
                return A1;
            }
            else if (A1 == null && A2 == null)
            {
                return null;
            }

            int A1LastPointer = length1 - 1;
            int A2LastPointer = length2 - 1;
            int AlTotalPointer = length1 + length2 - 1;
            for (int i = AlTotalPointer; i >= 0; i--)
            {
                if (A1[A1LastPointer] > A2[A2LastPointer])
                {
                    A1[AlTotalPointer] = A1[A1LastPointer];
                }
                else
                {
                    A1[AlTotalPointer] = A2[A1LastPointer];
                }
            }
            return A1;
        }
    }



    //编写测试用例
    //class Program
    //{
    //    static void Main()
    //    {
    //        //1. 输入包含空格的字符串
    //        Console.WriteLine(ReplaceBlank.ReplaceAllBlank2(new char[] { 'W','e',' ','a','r' },20));
    //        //2. 输入没有空格的字符串
    //        Console.WriteLine(ReplaceBlank.ReplaceAllBlank2(new char[] { 'W', 'e', 'a', 'r' }, 20));

    //        //Console.WriteLine(ReplaceBlank.ReplaceAllBlank("We are friend!"));

    //        //3. 输入空数组
    //        Console.WriteLine(ReplaceBlank.ReplaceAllBlank2(new char[] { ' ' }, 20));

    //        //Console.WriteLine(ReplaceBlank.ReplaceAllBlank(""));
    //        //Console.WriteLine(ReplaceBlank.ReplaceAllBlank(" "));
    //        //Console.WriteLine(ReplaceBlank.ReplaceAllBlank("   "));

    //        Console.ReadLine();
    //    }
    //}
}
