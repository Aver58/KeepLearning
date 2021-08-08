#region Copyright © 2020 Aver. All rights reserved.
/*
=====================================================
 AverFrameWork v1.0
 Filename:    Program.cs
 Author:      Zeng Zhiwei
 Time:        2020/11/12 20:12:30
=====================================================
*/
#endregion

using System;
using System.IO;
using System.Threading.Tasks;

class Template<T>
{
    bool IsEquals(T a,T b)
    {
        return a.Equals(b);
    }
}
public class Program
{
    public static async Task Method1()
    {
        await Task.Run(() =>
        {
            for(int i = 0; i < 100; i++)
            {
                Console.WriteLine("Method1 :" + i.ToString());
            }
        });
    }

    public static void Method2()
    {
        for(int i = 0; i < 25; i++)
        {
            Console.WriteLine("Method2 :"+ i.ToString());
        }
    }

    static void Main(string[] args)
    {
        //MyNamespace.List<int>.main();
        //MyNamespace.Dictionary<int, int>.main();

        //Method1();
        //Method2();
        //TestUnsafe();
        using(FileStream fs = new FileStream("File.txt",FileMode.Open))
        {
        }
        Console.ReadLine();
    }

    public unsafe static void TestUnsafe()
    {
        int var = 3000;
        int* ptr;
        int val;

        ptr = &var;// 获取 var 的地址
        val = *ptr;// 获取 ptr 的值
        Console.WriteLine(val.ToString());
    }

}