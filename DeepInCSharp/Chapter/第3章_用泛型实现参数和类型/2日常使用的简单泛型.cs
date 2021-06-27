using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace DeepInCSharp.第3章_用泛型实现参数和类型
{
    class _2日常使用的简单泛型
    {
        [STAThread]
        static void Mains()//要用的时候改成Main
        {
            string text = @"Do you like green eggs and ham?
                            I do not like them,Sam-I-am.
                            I do not like green eggs and ham.";
            var texts = CountWords(text);
            foreach (var item in texts)
            {
                String key = item.Key;
                int value = item.Value;
                Console.WriteLine("{0}:{1}", item.Key, item.Value);

            }

            Console.Clear();

            List<int> testInt = new List<int>();
            testInt.Add(1);
            testInt.Add(2);
            testInt.Add(3);
            testInt.Add(4);

            Converter<int, double> converter = TaskSquareRoot;//Converter<int, double>委托，输入int，输出double
            List<double> doubles = testInt.ConvertAll<double>(converter);
            foreach (var item in doubles)
            {
                Console.WriteLine(item);
            }

            Console.Clear();

            //var s = new { name = 1,age = 2 };
            //Console.WriteLine(s);
            List<string> lists = MakeList("1", "2");
            foreach (var item in lists)
            {
                Console.WriteLine(item);
            }
            Console.ReadLine();
        }


        /// <summary>
        /// 单词计数方法
        /// </summary>
        /// <param name="text"></param>
        /// <returns></returns>
        static Dictionary<string,int> CountWords(string text)
        {
            Dictionary<string, int> frequencies = new Dictionary<string, int>();
            string[] words = Regex.Split(text,@"\W+");//将文本分解成单词
            //foreach (var item in words)//文本末尾有个空字符串、是文本末尾的.句号造成的
            //{
            //    Console.WriteLine(item);
            //}
            foreach (var val in words)
            {
                var word = val.ToLower(); //解决没有考虑do和Do分开计数
                
                if (frequencies.ContainsKey(word))
                {
                    frequencies[word]++;
                }
                else
                {
                    frequencies[word] = 1;
                }
            }
            return frequencies;
        }

        /// <summary>
        /// 开根号
        /// </summary>
        /// <param name="x"></param>
        /// <returns></returns>
        static double TaskSquareRoot(int x)
        {
            return Math.Sqrt(x);
        }

        /// <summary>
        /// 生成List
        /// </summary>
        /// <typeparam name="T"></typeparam>
        /// <param name="first"></param>
        /// <param name="second"></param>
        /// <returns></returns>
        static List<T> MakeList<T>(T first,T second)
        {
            List<T> list = new List<T>();
            list.Add(first);
            list.Add(second);
            return list;
        }
    }
}
