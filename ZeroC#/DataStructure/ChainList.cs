using System;
using System.Collections;

namespace DataStructure
{
    public interface IChainList<T>
    {
        int GetLength();
        bool IsEmpty();
        void Clear();
        Node<T> Find(int i);
        int Index(T node);
        void Add(T item);
        void Delete(int i);
        void Insert(T item, int i);
        void Reverse();
    }

    //结点类
    public class Node<T>
    {
        public T data;          //数据域
        public Node<T> next;    //指针域

        public Node() { }

        public Node(T value)
        {
            data = value;
        }
    }


    /// <summary>
    /// 线性表的链式实现    -- 2018/7/20
    /// 单链表
    /// </summary>
    class ChainList<T> : IChainList<T>
    {
        private Node<T> m_HeadNode;
        private int m_Size = 0;

        public ChainList(T node)
        {
            //创建头结点
            m_HeadNode = new Node<T>(node);
            m_HeadNode.next = null;
            m_Size++;
        }

        public ChainList(T[] data,bool isInsertTop)
        {
            if (isInsertTop)
            {
                for (int i = 0; i < data.Length; i++)
                {
                    InsertTop(data[i]);
                }
            }
            else
            {
                for (int i = 0; i < data.Length; i++)
                {
                    Add(data[i]);
                }
            }
        }

        //输出线性表
        public void PrintNodes()
        {
            var tempNode = m_HeadNode;
            if (m_HeadNode.next == null)
            {
                Console.WriteLine("Current List Is Empty!");
                return;
            }
            while (tempNode != null)
            {
                Console.Write(tempNode.data + " ");
                tempNode = tempNode.next;
            }
            Console.WriteLine();
        }

        public int GetLength()
        {
            return m_Size;
        }

        public bool IsEmpty()
        {
            var tempNode = m_HeadNode.next;
            if (tempNode == null)
            {
                return true;
            }
            return false;
        }

        public void Clear()
        {
            m_HeadNode = new Node<T>();
            m_HeadNode.next = null;
        }

        public void Add(T node)
        {
            var temp = m_HeadNode;
            if (temp == null)
            {
                m_HeadNode = new Node<T>(node);
                m_HeadNode.next = null;
                m_Size++;
                return;
            }
            for (int i = 0; i < m_Size - 1; i++)
            {
                temp = temp.next;
            }
            var newNode = new Node<T>(node);
            newNode.next = null;
            temp.next = newNode;
            m_Size++;
        }

        public void Delete(int i)
        {
            if (i>m_Size||i<0)
            {
                Console.WriteLine("Out Of Index! m_Size is {0}", m_Size);
                return;
            }
            if (i==0)
            {
                //删除头结点
                m_HeadNode = m_HeadNode.next;
                m_Size--;
                return;
            }
            //找到第i-1个结点
            var temp = m_HeadNode;
            for (int j = 0; j < i - 1; j++)
            {
                temp = temp.next;
            }
            var preNode = temp;
            var target = temp.next;
            preNode.next = target.next;
            target = null;
            m_Size--;
        }

        public void Insert(T node, int i)
        {
            if (i > m_Size || i < 0)
            {
                Console.WriteLine("Out Of Index! m_Size is {0}", m_Size);
                return;
            }
            var temp = m_HeadNode;
            for (int j = 0; j < i - 1; j++)
            {
                temp = temp.next;
            }
            var preNode = temp;
            var target = temp.next;
            //申请新节点
            Node<T> newNode = new Node<T>(node);
            //先牵右手再牵左手
            newNode.next = target;
            preNode.next = newNode;
            m_Size++;
        }

        public void InsertTop(T node)
        {
            var temp = m_HeadNode;
            var newHead = new Node<T>(node);
            newHead.next = temp;
            m_HeadNode = newHead;
            m_Size++;
        }
        
        public Node<T> Find(int i)
        {
            Node<T> temp = m_HeadNode;
            if (i>m_Size||i<0)
            {
                Console.WriteLine("Out Of Index! m_Size is {0}", m_Size);
                return null;
            }
            for (int j = 0; j < i; j++)
            {
                temp = temp.next;
            }
            return temp;
        }

        public int Index(T node)
        {
            var temp = m_HeadNode;
            for (int i = 0; i < m_Size; i++)
            {
                if (temp.data.Equals(node))
                {
                    return i;
                }
                temp = temp.next;
            }
            Console.WriteLine("Without this item");
            return -1;
        }

        public void Reverse()
        {
            //m_HeadNode.next = null;
            //var temp = m_HeadNode;
            //for (int i = 0; i < m_Size/2; i++)
            //{
            //    var nextNode = temp.next;
            //    if (nextNode == null)
            //    {
            //        break;
            //    }
            //    else
            //    {
            //        var target = nextNode.next;
            //        if (target == null)
            //        {
            //            nextNode.next = temp;
            //            temp = nextNode;
            //        }
            //        else
            //        {
            //            nextNode.next = temp;
            //            temp = target;
            //        }
            //    }
            //}
            //m_HeadNode = temp;
        }
    }

    //class Program
    //{
    //    static void Main(string[] args)
    //    {
    //        ChainList<int> list = new ChainList<int>(new int[] {1,2,3},false);
    //        //list.Add(2);
    //        //list.Add(3);
    //        //list.Add(4);
    //        //list.Add(5);
    //        //list.Delete(2);

    //        //Console.WriteLine(list.Find(1).data);
    //        //Console.WriteLine(list.Index(4));

    //        //list.Insert(10,2);
    //        //list.Insert(100, 0);

    //        //list.InsertTop(10);
    //        list.Reverse();
    //        list.PrintNodes();

    //        Console.WriteLine(list.GetLength());
    //        Console.WriteLine(list.IsEmpty());

    //        //Console.Clear();

    //        Console.ReadLine();
    //    }
    //}
}
