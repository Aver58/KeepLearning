using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DeepInCSharp.第3章_用泛型实现参数和类型
{
    class _3类型约束
    {
        /*
         约束：
            1、引用类型约束where T:class
                struct RefSample<T> where T:class
            2、值类型约束where T:struct
                class ValueSample<T> where T : struct
            3、构造函数类型约束where T:new()
                
            4、转换类型约束：
                一种约束允许你指定另一种类型，类型实参必须通过
                一致性、引用或者装箱转换  隐式转换成该类型
                
             */
        static void Mains()//要用的时候改成Main
        {
            //有效类型，refsample实际上还是属于stuct结构，只是制定T类型要是引用类型
            ReferenceSample<string> s = new ReferenceSample<string>();
            s.Data = "string";
            Console.WriteLine(s.Data.GetType());
            ValueSample<int> f = new ValueSample<int>();
            Console.WriteLine(f.Data.GetType());
            //Console.Clear();


            Console.ReadKey();
        }

    

        //1.引用类型约束
        struct ReferenceSample<T> where T : class
        {
            public T Data;
            /*
                有效：
                ReferenceSample<IDisposable>
                ReferenceSample<string>
                ReferenceSample<int[]>
                无效
                ReferenceSample<Guid>
                ReferenceSample<int>
             */
        }
         //2、值类型约束
        class ValueSample<T> where T : struct
        {
            public T Data = new T();
            /*
               有效：
               ValueSample<int>
               ValueSample<FileMode>//枚举
               无效--可空类型也无效
               ValueSample<object>
               ValueSample<StringBuilder>
            */
        }
        //3、构造函数类型约束
        public T CreateInstance<T>()where T:new()
        {
            return new T();
        }
        //4、转换类型约束：
        class Sample1<T> where T : Stream
        {
            //Sample1<Stream> s;//一致性转换
        }
        class Sample2<T> where T : IDisposable
        {
            //Sample2<SqlConnection> s;//引用转换
        }
        class Sample3<T> where T : IComparable<T>
        {
            //Sample3<int> s;     //装箱转换
            //Sample3<long> s1;   //装箱转换
        }
        class Sample4<T,U> where T : U
        {
            //Sample4<Stream,IDisposable> s;//引用转换
            //Sample4<string,IDisposable> s1;
        }


    }
}
