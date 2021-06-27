using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Algorithm
{
    class GetArrayOtherMutipleClass
    {
        //Product of Array Except Self 求数组中除本身元素之外的其他元素的乘积，不用除法
        //输入一个数组，返回一个数组，
        //返回的数组中A[i] 表示原数组中除了第i个以外的所有元素的乘积
        //例：
        //输入：{1,2,3,4}
        //输出：{24,12,8,6}

        /// <summary>
        /// 先写个n平方算法
        /// </summary>
        public static int[] ArrayExceptSelfNN(int[] input)
        {
            if (input == null)
            {
                Console.WriteLine("null");
                return null;
            }
            int length = input.Length;
            var output = new int[length];
            for (int i = 0; i < length; i++)
            {
                output[i] = 1;
                for (int j = 0; j < input.Length; j++)
                {
                    if (i!=j)
                    {
                        output[i] *= input[j];
                    }
                }
            }
            return output;
        }

        //分析：
        //1、如果数组中有两个及以上的0，那么结果数组的每一项都为0.
        //2、如果数组中只有一个0，那么结果数组中，0对应的位置，为数组中其他元素的成绩，其余位置都为0。
        //3、如果数组中没有0，那么结果数组每一项均为数组所有元素的乘积/当前数组元素。
        //需要扫描数组两次，算法时间复杂度为O（n）：
        //第一次：计算0的个数，以及非0元素的乘积。
        //第二次，计算结果数组每一位的元素。
        //左边 * 右边
        public static int[] ArrayExceptSelf2N(int[] input)
        {
            if (input == null)
            {
                Console.WriteLine("null");
                return null;
            }

            int length = input.Length;
            var left = new int[length];
            var right = new int[length];
            var output = new int[length];
            left[0] = 1;
            right[length - 1] = 1;
            //先算出左边的
            for (int i = 1; i < length; i++)
            {
                left[i] = left[i - 1] * input[i - 1];
            }

            //倒数第二个开始，最后一个是length - 1,
            for (int i = length - 2; i >= 0; i--)
            {
                right[i] = right[i + 1] * input[i + 1];
            }

            for (int i = 0; i < length; i++)
            {
                output[i] = left[i] * right[i];
            }
            return output;
        }

        public static int[] ArrayExceptSelfN(int[] input)
        {
            if (input == null)
            {
                Console.WriteLine("null");
                return null;
            }

            int length = input.Length;
            var output = new int[length];
            var right = 1;
            output[0] = 1;

            for (int i = 1; i < length; i++)
            {
                output[i] = output[i - 1] * input[i - 1];
            }

            for (int i = length - 2; i >= 0; i--)
            {
                right *= input[i + 1];
                output[i] *= right;
            }
          
            return output;
        }
    }
}
