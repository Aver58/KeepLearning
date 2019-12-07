using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Algorithm.ToOffer
{

    public class Stack2Queue<T>
    {
        /*
            用2个栈实现队列
            先入先出
        */
        //一个栈用来充当入队，一个出队
        //入队就把popStack都弹出来，压进pushStack,pushStack弹出的第一个就是入队的那个
        //出队就把pushStack都弹出来，压进popStack,popStack弹出的第一个就是出队的那个

        Stack pushStack;
        Stack popStack;
        public Stack2Queue()
        {
            pushStack = new Stack();
            popStack = new Stack();
        }
        public Stack2Queue(T value)
        {
            pushStack = new Stack();
            popStack = new Stack();
            pushStack.Push(value);
        }

        /// <summary>
        /// 在队列尾部插入
        /// </summary>
        public void AppendTail(int value)
        {
            while (popStack.Count > 0)
            {
                pushStack.Push(popStack.Pop());
            }

            pushStack.Push(value);
        }
        /// <summary>
        /// 删除头部
        /// </summary>
        public void DeleteHead()
        {
            while (pushStack.Count > 0)
            {
                popStack.Push(pushStack.Pop());
            }
            popStack.Pop();
        }

        public void PrintQueue()
        {
            while (pushStack.Count > 0)
            {
                popStack.Push(pushStack.Pop());
            }
            var temp = popStack;
            while (temp.Count > 0)
            {
                Console.WriteLine(temp.Pop());
            }
        }
    }
    public class Queue2Stack<T>
    {
        /*
            用2个队列实现栈
            后入先出
        */
        //一个队列用来充当进栈，一个用来出栈

        Queue pushQueue;
        Queue popQueue;
        public Queue2Stack()
        {
            pushQueue = new Queue();
            popQueue = new Queue();
        }
        public Queue2Stack(T value)
        {
            pushQueue = new Queue();
            popQueue = new Queue();
            pushQueue.Enqueue(value);
        }

        /// <summary>
        /// 在队列尾部插入
        /// </summary>
        public void AppendTail(int value)
        {
            for (int i = 0; i < popQueue.Count; i++)
            {
                pushQueue.Enqueue(popQueue.Dequeue());
            }
            pushQueue.Enqueue(value);
        }
        /// <summary>
        /// 删除头部
        /// </summary>
        public void DeleteHead()
        {
            for (int i = 0; i < pushQueue.Count; i++)
            {
                popQueue.Enqueue(pushQueue.Dequeue());
            }
            popQueue.Dequeue();
        }
    }

    //class Program
    //{
    //    static void Main()
    //    {
    //        Stack2Queue<int> sQueue = new Stack2Queue<int>(1);
    //        sQueue.AppendTail(2);
    //        sQueue.AppendTail(3);
    //        sQueue.AppendTail(4);
    //        sQueue.AppendTail(5);
    //        sQueue.AppendTail(6);
    //        sQueue.DeleteHead();
    //        sQueue.PrintQueue();
    //        //1. 输入包含空格的字符串
    //        //2. 输入没有空格的字符串


    //        //3. 输入空数组
    //        //Console.WriteLine(ReplaceBlank.ReplaceAllBlank2(new char[] { ' ' }, 20));

    //        Console.ReadLine();
    //    }
    //}
}
