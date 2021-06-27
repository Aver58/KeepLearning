using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DeepInCSharp.第二章_C1搭建的核心基础
{
    class _1委托
    {
        /*换言之，指示别人去做事，但不知道他具体会怎么做，因为当事人已经死了。
        //委托类型和委托实例的区别：就相当于与类与类的实例


        //委托构成的4个条件
        //1.声明委托类型
        //2.必须有一个方法包含了要执行的代码
        //3.必须创建一个委托实例
        //4.必须调用委托实例
       
        总结:
            1.委托实例是不易变的
            2.事件类似于委托的属性：事件添加的一个封装层实现发布/订阅模式
             */
    }


    //简单委托例子    
    delegate void StringProcessor(string input);//1.声明委托类型

    class Person
    {
        string name;
        public Person(string name)
        {
            this.name = name;
        }
        public void Say(string message) //2.必须有一个方法包含了要执行的代码
        {
            Console.WriteLine("{0} says:{1}",name,message);
        }

        public void Say2(string message) //2.必须有一个方法包含了要执行的代码
        {
            Console.WriteLine("{0} says:{1}", name, message + "Say2");
        }

       
    }
    class Background
    {
        public static void Note(string note) //2.必须有一个方法包含了要执行的代码
        {
            Console.WriteLine("({0})--BG", note);
        }
    }
    class SimpleDelegateTest
    {
        [STAThread]
        static void Mains()//要用的时候改成Main
        {
            //委托区
            Person jon = new Person("Jon");
            Person tom = new Person("Tom");
            StringProcessor jonsVoice, tomsVoice, background;
            jonsVoice = new StringProcessor(jon.Say);//3.必须创建一个委托实例
            jonsVoice += jon.Say2;//合并委托、订阅委托
            jonsVoice -= jon.Say2;//移除委托、取消委托
            tomsVoice = new StringProcessor(tom.Say);
            background = new StringProcessor(Background.Note);
            jonsVoice("Hello");//4.必须调用委托实例
            tomsVoice("there");
            tomsVoice.Invoke("there2");
            background("I'm BG");

            Console.ReadLine();
        }
    }
    
}
