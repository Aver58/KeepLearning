using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Algorithm.ToOffer
{
    class _08_RotateArray
    {
        /*
         把一个数组的若干元素搬到数组的末尾，我们称之为数组的旋转。
         输入一个递增数组的一个旋转，输出最小值
         input：{3,4,5,6,1,2}
         output：1
             */
        public static int FindMinInRotateArray(int[] array)
        {
            int length = array.Length;
            if (array == null|| length <= 0)
            {
                throw new Exception("array is NUll!");
            }

            int index1 = 0;
            int index2 = length-1;
            int indexMiddle = index1;

            while (array[index1] >= array[index2])
            {
                if (index2 - index1 == 1)
                {
                    indexMiddle = index2;
                    break;
                }

                indexMiddle = (index1 + index2) / 2;

                //如果下标 index1 == index2 == indexMiddle
                //只能顺序查找
                if (array[index1] == array[index2] 
                    || array[index1] == array[indexMiddle]
                    || array[index2] == array[indexMiddle])
                {
                    return FindMinInOrder(array);
                }

                if (array[index1] <= array[indexMiddle])
                {
                    index1 = indexMiddle;
                }
                else if (array[index2] >= array[indexMiddle])
                {
                    index2 = indexMiddle;
                }
            }
            return array[indexMiddle];
        }
        static int FindMinInOrder(int[] array)
        {
            int min = array[0];
            for (int i = 0; i < array.Length; i++)
            {
                if (array[i]<min)
                {
                    min = array[i];
                }
            }
            return min;
        }

        //编写测试用例
        //class Program
        //{
            //static void Main()
            //{
            //    Console.WriteLine(FindMinInRotateArray(new int[] { 3, 4, 5, 6, 1, 2 }));
            //    Console.WriteLine(FindMinInRotateArray(new int[] { 1, 1, 1, 1, 0, 1 }));
            //    Console.WriteLine(FindMinInRotateArray(new int[] { }));
            //    Console.ReadLine();
            //}
        //}
    }
}
