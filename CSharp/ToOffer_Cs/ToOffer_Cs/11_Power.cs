using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Algorithm.ToOffer
{
    class _11_Power
    {
        //设置一个全局变量，来区分是0次方的0还是无效输入的0
        static bool _invalidInput = false;
        //求X的整数次方，不得使用库函数，不考虑大数问题
        public static double Power(double baseValue,int exponent)
        {
            _invalidInput = false;
            if (Equal(baseValue,0.0)&&exponent <= 0)
            {
                _invalidInput = true;
                Console.WriteLine("Invalid Input");
                return 0.0;
            }

            double result = PowerWithUnsigned(baseValue, Math.Abs(exponent));
            if (exponent < 0)
                return 1.0 / result;

            return result; 
        }

        static double PowerWithUnsigned(double baseValue, int exponent)
        {
            if (Equal(exponent, 0.0))
                return 1.0;

            if (exponent == 1)
                return baseValue;

            double result = PowerWithUnsigned(baseValue,exponent>>1);
            result *= result;

            if ((exponent & 1) == 1)
                result *= baseValue;

            return result;
        }
  
        /// <summary>
        /// 由于计算机表示小数有误差
        /// </summary>
        /// <param name="num1"></param>
        /// <param name="num2"></param>
        /// <returns></returns>
        static bool Equal(double num1,double num2)
        {
            if ((num1 - num2 > -0.0000001) &&(num1 - num2 < 0.0000001))
            {
                return true;
            }
            return false;
        }

        //class Program
        //{
        //    static void Main()
        //    {
        //        Console.WriteLine(Power(0,0));
        //        Console.WriteLine(Power(2,0));
        //        Console.WriteLine(Power(2,1));
        //        Console.WriteLine(Power(2,2));
        //        Console.WriteLine(Power(2,3));
        //        Console.WriteLine(Power(2,5));

        //        Console.ReadLine();
        //    }
        //}
    }
}
