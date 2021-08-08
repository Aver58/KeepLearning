using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DeepInCSharp.第二章_C1搭建的核心基础
{
    class _4构建在坚实基础之上的新特性
    {
        /*
         摘要：
            几个新特性：泛型、可空、委托、迭代器
             */
        ///演示C#2在委托实例上的改进
        static void HandleDemoEvent(object sender,EventArgs e)
        {
            Console.WriteLine("Handled by HandleDemoEvent");
        }


        [STAThread]
        static void Mains()//要用的时候改成Main
        {
            EventHandler handler;
            handler = new EventHandler(HandleDemoEvent);   //1.指定委托类型和方法
            handler(null, EventArgs.Empty);

            handler = HandleDemoEvent;                     //1.1指定委托类型和方法（简写）
            handler(null, EventArgs.Empty);

            Action<object, EventArgs> funcs = HandleDemoEvent;//1.3使用Action
            funcs(null, EventArgs.Empty);

            handler = delegate (object sender, EventArgs e)//2.使用匿名方法
            {
                Console.WriteLine("Handled by Anonymously");
            };
            handler(null, EventArgs.Empty);

            handler = delegate                             //2.1使用匿名方法(简写)
            {
                Console.WriteLine("Handled by Anonymously Again！");
            };
            handler(null, EventArgs.Empty);

            //MouseEventHandler mouseHandler = HandleDemoEvent;//使用委托逆变性:todo事件还是委托实例没看懂
            //mouseHandler(null,new MouserEventArgs(MouseButtons.None,0,0,0,0));

            ///Lambda表达式是改进后的匿名方法
            Func<int, int, string> func = (x, y) => (x * y).ToString();
            Console.WriteLine(func(5,6));//输出30

            Console.Clear();

            var jon = new { Name = "Jon",Age = 31};//new { }匿名对象初始化
            var tom = new { Name = "Tom",Age = 3};
            Console.WriteLine("{0} is {1}",jon.Name,jon.Age);
            Console.WriteLine("{0} is {1}", tom.Name, tom.Age);

            var s = "olleH".Reverse();//string 的拓展方法
            StringBuilder sb = new StringBuilder();
            foreach (var item in s)
            {
                sb.Append(item);
            }
            Console.WriteLine(sb);
            //Console.WriteLine(s);//Enumerable+<ReverseIterator>d__75`1[System.Char]

            Console.Clear();


            int? a = null;       //声明可空类型
            a = 5;
            if (a!= null)
            {
                int y = a.Value; //获取真正的值
                Console.WriteLine(y);
            }
            int z = a ?? 10;     //使用null联合操作符：如果a=null,就赋10，不然就是a
            Console.WriteLine(z);//输出5

            Console.ReadLine();
        }
    }
}
