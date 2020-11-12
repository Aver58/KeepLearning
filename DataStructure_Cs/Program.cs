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

public class Program
{
    static void Main(string[] args)
    {
        MyNamespace.List<int> testList = new MyNamespace.List<int>();
        testList.Add(1);
        testList.Add(2);
        testList.Add(3);
        testList.Add(4);
        testList.Insert(0,4);
        foreach(int item in testList)
        {
            Console.WriteLine(item);
        }

        Console.ReadLine();
    }
}