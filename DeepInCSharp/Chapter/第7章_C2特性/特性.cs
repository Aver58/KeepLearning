using System;
using Winform = System.Windows.Forms;
using Webform = System;


namespace DeepInCSharp.第7章
{
    class Character
    {
        /*
        1.C#2 4大特性：泛型、可空、委托增强、迭代器

        2.分部类型partial class
            C#3 提供了分部方法
            partial void function
        3.静态类型static
            所有成员都是静态的（除了私有构造函数）
            类之间从object派生
            一般情况不应该有状态，除非涉及告诉缓存或者单例
            不能存在任何可见的构造函数
            添加sealed class修饰符，不能派生子类
        4.命名空间别名
            using Winform = System.Windows.Forms;
        5.pragma指令 
            #pragma预处理指令

         */
        static void Mains()//要用的时候改成Main
        {
            Console.WriteLine(typeof(Winform::Button));
            Console.ReadLine();
        }
    }
}