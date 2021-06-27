using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DeepInCSharp.第二章_C1搭建的核心基础
{
    class _2类型系统的特征
    {
        /*
         2.2
            1.C#1 是静态类型--编译器指定你能使用哪些成员
            2.C#1 是显式的--除非告诉编译器变量具有什么类型
            3.C#1 是安全的--除非存在真是的转换关系，否则不能讲一种类型当做另一种
         2.3 值类型和引用类型
            特殊：
            1.结构Struct是值类型，类Class是引用类型
            2.int是值类型；      而int[]是引用类型
            3.枚举enum是值类型，
            4.委托delegate是引用类型
            5.接口interface是引用类型，但可由值类型实现
            区别：
                1.位置存储：引用类型存在堆中,而值类型是在声明位置存储的。
                注意：如果一个类中有个int 实例，那它的位置就在堆上创建，
                      只有局部变量和方法参数在栈上
            
        2.3.4装箱和拆箱：
            int i = 5;
            object o = i;
            int j = (int)o;
            运行时在堆上创建一个值为5的对象。o是对该对象的引用，
            改变i的值不会改变箱内的值
        2.3.5值类型和引用类型小结
            1.引用类型对象总算在堆上、值类型的值可能在堆上，也可能在栈上



         */
        [STAThread]
        static void Mains()//要用的时候改成Main
        {
            int i = 5;
            object o = i;
            int j = (int)o;
            //long j = (long)o;//System.InvalidCastException
            Console.WriteLine(j);

            Console.ReadLine();
        }
    }
}
