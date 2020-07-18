using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace Algorithm.ToOffer
{
    class StructAndclass
    {
        #region C#和C++Struct和class的区别
        /*
         1.在c++ 中Struct和class的区别
            在没标明访问修饰符的情况下，struct默认是public，class默认是private；
         2.在c# 中Struct和class的区别
            在没标明访问修饰符的情况下，都是private；
            - struct 定义的是值类型，值类型的实例在栈上分配内存；
            - class 定义的是引用类型，引用类型的实例在堆上分配内存；
         */
        #endregion

        #region C++的析构和C#的Finalizer
        //3. C++的析构需要自己控制，C#定义了Finalizer和Dispose来释放资源，
        //   Finalizer方法是在CLR做垃圾回收时才被调用，对程序员来说不可控。
        #endregion

        #region 静态构造函数
        public class A
        {
            static A() {
                Console.WriteLine("A Static"); //②静态构造函数
            }
            public A() {
                Console.WriteLine("A new");//③构造函数
            }
        }

        public class B
        {
            static A a  = new A();      //①静态构造变量先走
            static B()
            {
                Console.WriteLine("B Static");//④静态构造函数
            }
            public B()
            {
                Console.WriteLine("B new");//⑤构造函数
            }
        }


        class Program
        {
            static void Mains()
            {
                //0.调用开始
                B b = new B();
                Console.ReadLine();
            }
        }



        #endregion

        #region C#的反射、应用程序域

        //加上[Serializable]才能实现用反射调用
        //如果你做远程方法调用(RPC）时，
        //比如，服务器端有个类A及对象a，客户端需要无视网络的存在，直接调用对象a。
        //这种情况下，就需要把类A设计为可序列化的，那么它的实例a也就可以实例化了。
        [Serializable]
        //继承MarshalByRefObject，那么C相当于原先作用域的一个代理，它将指针指向
        //新作用域的实例，那调用新作用域的方法，改变的值也是新作用域的值，所以输出了10；
        internal class C : MarshalByRefObject
        {
            public static int Number;
            public void SetNumber(int value)
            {
                Number = value;
            }
        }

        [Serializable]
        internal class D 
        {
            public static int Number;
            public void SetNumber(int value)
            {
                Number = value;
            }
        }

        class Programs
        {
            static void Mains()
            {
                //创建一个新的程序集
                string assembly = Assembly.GetEntryAssembly().FullName;
                AppDomain domain = AppDomain.CreateDomain("NewDomain");

                C.Number = 10;
                string C_Name = typeof(C).FullName;
                //用反射创建一个C的实例
                C c = domain.CreateInstanceAndUnwrap(assembly, C_Name) as C;
                c.SetNumber(20);

                //D在跨越作用域的时候，引用复制了一份实例，
                //所以调用新作用域的方法，改变的是默认作用域的值,所以输出20.
                D.Number = 10;
                string D_Name = typeof(D).FullName;
                D d = domain.CreateInstanceAndUnwrap(assembly, D_Name) as D;
                d.SetNumber(20);

                Console.WriteLine(C.Number + " " + D.Number);
                Console.ReadLine();
            }
        }

        #endregion
    }
}
