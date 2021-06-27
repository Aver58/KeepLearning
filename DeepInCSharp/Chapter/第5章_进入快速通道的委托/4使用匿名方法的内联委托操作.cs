using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DeepInCSharp.第5章_进入快速通道的委托
{
    class 使用匿名方法的内联委托操作
    {
        static void Mains()//要用的时候改成Main
        {
            printReverse("hello");
            printSqrt(4);
            printAvg(new double[] { 1,2,3,4,5});
            //public delegate bool Predicate<T>(T obj);

            Console.Clear();

            Predicate<int> isEven = delegate (int x) { return x % 2 == 0; };//判断是否偶数

            Console.WriteLine(isEven(1));
            Console.WriteLine(isEven(4));

            Console.Clear();

            SortAndShowFiles("Sort by name",delegate(FileInfo f1, FileInfo f2) { return f1.Name.CompareTo(f2.Name); });
            SortAndShowFiles("Sort by Length", delegate (FileInfo f1, FileInfo f2) { return f1.Length.CompareTo(f2.Length); });


            Console.ReadKey();
        }

        /// <summary>
        /// 按不同的规则排序C盘文件信息
        /// </summary>
        /// <param name="title">规则，给自己看的文字</param>
        /// <param name="sortOrder">委托，排序规则</param>
        static void SortAndShowFiles(string title,Comparison<FileInfo> sortOrder)
        {
            FileInfo[] files = new DirectoryInfo(@"C:\").GetFiles();

            Array.Sort(files,sortOrder);
            Console.WriteLine(title);
            foreach (var item in files)
            {
                Console.WriteLine("{0}({1}bytes)",item.Name,item.Length);
            }
        }

        static Action<string> printReverse = delegate (string text){
            char[] chars = text.ToCharArray();
            Array.Reverse(chars);
            Console.WriteLine(new string (chars));
        };

        static Action<int> printSqrt = delegate (int number)
        {
            Console.WriteLine(Math.Sqrt(number));
        };
        /// <summary>
        /// 求平均
        /// </summary>
        static Action<IList<double>> printAvg = delegate (IList<double> number)
        {
            double total = 0;
            foreach (var item in number)
            {
                total += item;
            }
            Console.WriteLine(total/number.Count);
        };

    }
}
