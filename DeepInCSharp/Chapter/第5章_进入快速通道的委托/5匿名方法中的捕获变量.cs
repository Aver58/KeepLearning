using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DeepInCSharp.第5章_进入快速通道的委托
{
    class 匿名方法中的捕获变量
    {
        /*
            定义闭包和不同类型的变量
                1.外部变量
                2.捕获的外部变量
            每声明一次局部变量，它就被实例化一次。

            总结：
            使用捕获变量时候的规则：
                1.用不用的都可以的时候就不用
                2.捕获for或者foreach语句声明的变量之前，要注意，是要声明内部局部变量还是使用共享变量
                3.如果创建多个委托实例，而且捕获了变量，思考一下是否希望他们捕获到同一个变量
                4.如果捕获的变量不会发生改变，就不必担心
            要点：
                1.捕获的是变量，而不是创建委托实例的值
                2.捕获的变量的生存期被延长了，只是和捕捉它的委托一样长。
                3.多个委托可以捕获同一个变量
                4.但在循环内部，同一个变量声明实际上回引用不同的变量“实例”
                5.在for循环的声明中创建的变量（例如for(int i= 0; i<2;i++)中的i）仅在循环持续期间有效——不会每次都实例化
                6.必要的时候要创建额外的类型来保存捕获变量
             */

        static void Mains()//要用的时候改成Main
        {
            EnclosingMethod();

            TestVariables();

            TestSameVariable();

            Console.Clear();

            TestMixVariables();

            Console.ReadKey();
        }

        /// <summary>
        /// 不在不同作用域的变量
        /// </summary>
        static void TestMixVariables()
        {
            MethodInvoker[] delegates = new MethodInvoker[2];

            int outside = 0;//被两个委托实例共享

            for (int i = 0; i < 2; i++)
            {
                int inside = 0;//每次都被实例化
                delegates[i] = delegate {
                    Console.WriteLine("{0},{1}",outside,inside);
                    outside++;
                    inside++;
                };
            }
            MethodInvoker first = delegates[0];
            MethodInvoker second = delegates[1];

            first();//0,0
            first();//1,1
            first();//2,2

            second();//3,0
            second();//4,1

        }

        /// <summary>
        /// 委托实例捕获的是不同的变量
        /// </summary>
        static void TestVariables()
        {
            List<MethodInvoker> list = new List<MethodInvoker>();
            for (int i = 0; i < 5; i++)
            {
                int counter = i * 10;
                list.Add(delegate
                {
                    Console.WriteLine(counter);
                    counter++;
                });
            }
            foreach (var item in list)
            {
                item();//输出0、10、20、30、40
            }
            list[0]();//输出1
            list[0]();//输出2
            list[0]();//输出3

            list[1]();//输出11
            //所以每个委托实例捕获的是不同的变量
        }

        /// <summary>
        /// 用同一个变量：
        /// </summary>
        static void TestSameVariable()
        {
            List<MethodInvoker> list = new List<MethodInvoker>();
            for (int i = 0; i < 5; i++)
            {
                int counter = i * 10;
                list.Add(delegate
                {
                    Console.WriteLine(counter);
                    counter++;
                });
            }
            foreach (var item in list)
            {
                item();//输出5-9
            }
            list[0]();//输出10
            list[0]();//输出11
            list[0]();//输出12

            list[1]();//输出13
            //用相同的变量
        }
        /// <summary>
        /// 闭包
        /// </summary>
        static void EnclosingMethod()
        {
            int outerVariable = 5;                             //外部变量（未捕获的变量）
            string captureVariable = "captured";               //外部变量（被匿名方法捕获的变量）
            if (DateTime.Now.Hour == 23)
            {
                int normalLocalVariable = DateTime.Now.Minute; //普通方法的局部变量
                Console.WriteLine(normalLocalVariable);
            }
            MethodInvoker x = delegate ()
            {
                string anonLocal = "local to anonymous method";//匿名方法的局部变量
                Console.WriteLine(captureVariable + anonLocal);//捕获外部变量
            };
            x();
        }
    }
}
