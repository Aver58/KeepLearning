using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataStructure
{
    public interface IStackList<T>
    {
        int GetLength();
        bool IsEmpty();
        void Clear();
        T Find(int i);
        int? Index(T node);
        void Push(T node);
        T Pop();
    }
    /// <summary>
    /// 栈的实现
    /// </summary>
    /// <typeparam name="T"></typeparam>
    class StackList<T>: IStackList<T>, IEnumerable
    {

        T[] m_Items;
        int m_Top;//栈顶
        int m_Top2;//栈顶2
        int m_Size;
        public StackList(int size)
        {
            m_Items = new T[size];
            m_Top = -1;
            m_Top2 = size;
            m_Size = size;
        }

        public IEnumerator GetEnumerator()
        {
            foreach (var item in m_Items)
            {
                yield return item;
            }
        }

        public int GetLength()
        {
            return m_Size;
        }

        public bool IsEmpty()
        {
            return m_Top == -1;
        }

        public bool IsFull()
        {
            return m_Top == (m_Size - 1);
        }

        public void Clear()
        {
            if (IsEmpty())
            {
                Console.WriteLine("Current List Is Empty!");
                return;
            }
            m_Top = -1;
            m_Size = 0;
            for (int i = 0; i < m_Items.Length; i++)
            {
                m_Items[i] = default(T);
            }
        }

        public T Find(int i)
        {
            if (IsEmpty())
            {
                Console.WriteLine("Current List Is Empty!");
                return default(T);
            }
            if (i > m_Top - 1 || i < 0)
            {
                Console.WriteLine("Stack Overflow! m_Top is at {0}", m_Top);
                return default(T);
            }
            return m_Items[i - 1];
        }

        public int? Index(T node)
        {
            if (IsEmpty())
            {
                Console.WriteLine("Current List Is Empty!");
                return null;
            }
            for (int i = 0; i < m_Size-1; i++)
            {
                if (m_Items[i].Equals(node))
                {
                    return i;
                }
            }
            Console.WriteLine("Not found this node!");
            return null;
        }

        public void Push(T node)
        {
            if (IsFull())
            {
                Console.WriteLine("Current List Is IsFull!");
                return;
            }
            m_Top++;
            m_Items[m_Top] = node;
        }

        public T Pop()
        {
            if (IsEmpty())
            {
                Console.WriteLine("Current List Is Empty!");
                return default(T);
            }
            var top = m_Top;
            var topValue = m_Items[top];
            m_Items[top] = default(T);
            m_Top--;
            return topValue;
        }

        /// <summary>
        /// 用一个数组实现2个堆栈
        /// 从数组2头向中间生长，2个堆栈相遇就是堆栈满了
        /// </summary>
        /// <param name="node"></param>
        /// <param name="Top"></param>
        public void Push(T node,bool Top1)
        {
            if (m_Top2 - m_Top == 1)
            {
                Console.WriteLine("Current List Is IsFull!");
                return;
            }
            if (Top1)
            {
                m_Top++;
                m_Items[m_Top] = node;
            }
            else
            {
                m_Top2--;
                m_Items[m_Top2] = node;
            }
        }

        public T Pop(T node, bool Top1)
        {
            if ((Top1&&m_Top==0)||(!Top1 && m_Top2 == m_Size))
            {
                Console.WriteLine("Current List Is Empty!");
                return default(T);
            }
            if (Top1)
            {
                var top = m_Top;
                var topValue = m_Items[top];
                m_Items[top] = default(T);
                m_Top--;
                return topValue;
            }
            else
            {
                var top = m_Top2;
                var topValue = m_Items[top];
                m_Items[top] = default(T);
                m_Top++;
                return topValue;
            }
         
        }
        //这是我自己写的一个简单的中缀表达式求值程序，简单到只能计算10以内的数，支持+-*/() 运算符。
        int GetPriority(char str)
        {
            switch (str)
            {
                case '(':
                    return -2;
                case ')':
                    return -1;
                case '*':
                    return 0;
                case '/':
                    return 0;
                case '+':
                    return 1;
                case '-':
                    return 1;
                default:
                    return 999;
            }
        }
        /// <summary>
        /// 中缀表达式如何转换为后缀表达式
        /// 输入1+2*(3+4)
        /// 输出1234+*+
        ///  2*(9+6/3-5)+4
        ///  2963/+5-*4+
        /// </summary>
        public void InfixToSuffix(string expression)
        {
            StackList<string> stack = new StackList<string>(100);
            var chars = expression.ToCharArray();
            //foreach (var str in chars)
            //{
            //    var priority = GetPriority(str);
            //    switch (priority)
            //    {
            //        case -1:
            //            stack.Push(str.ToString());
            //            break;
            //        case 0:
            //            stack.Push(str.ToString());
            //            break;
            //        case 1:
            //            stack.Push(str.ToString());
            //            break;
            //            //default:
            //    }
            //}
           
        }
    }
    //class Program
    //{
    //    static void Main(string[] args)
    //    {
    //        StackList<int> list = new StackList<int>(10);
    //        list.Push(1);
    //        list.Push(2);
    //        list.Pop();
    //        foreach (var item in list)
    //        {
    //            Console.WriteLine(item);
    //        }

    //        Console.WriteLine("Length:{0}",list.GetLength());
    //        Console.WriteLine("IsFull:{0}", list.IsFull());
    //        Console.WriteLine("IsEmpty:{0}", list.IsEmpty());
    //        //Console.WriteLine(list[1]);

    //        //Console.Clear();

    //        //list.Insert(100, 0);
    //        //list.Insert(22, 1);

    //        //list.Delete(0);
    //        //Console.WriteLine(list.GetLength());
    //        //foreach (var item in list)
    //        //{
    //        //    Console.WriteLine(item);
    //        //}
    //        Console.ReadLine();
    //    }
    //}
}
