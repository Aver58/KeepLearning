using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataStructure
{
    //别人写的
    class LinkListTest
    {
        public int COUNT = 0;//线性表元素的个数

        private static LinkListTest _instance = null;
        public static LinkListTest Instance
        {
            get
            {
                if (_instance == null)
                    _instance = new LinkListTest();
                return _instance;
            }
        }

        //内部结点类
        public class Node<T>
        {
            public T data; //数据域
            public Node<T> next; //指针域

            public Node()   { }

            public Node(T value)
            {
                this.data = value;
            }
        }

        //头插法创建线性表 线性表的数据与输入的数据顺序相反
        //类似于插队，始终让新结点在第一的位置
        public Node<T> CreateListHead<T>(T[] datas)
        {
            //创建一个带头结点的单链表
            Node<T> headNode = new Node<T>();
            headNode.next = null;
            COUNT = 0;

            for (int i = 0; i < datas.Length; i++)
            {
                //给headNode链表创建新的结点
                Node<T> newNode = new Node<T>(datas[i]);
                newNode.next = headNode.next;
                headNode.next = newNode;
                COUNT++;
            }
            return headNode;
        }

        //输出线性表
        public void PrintLinkList<T>(Node<T> head)
        {
            Node<T> tempNode = head.next;
            if (head.next == null)
            {
                Console.WriteLine("当前线性表为空！");
            }
            while (tempNode != null)
            {
                Console.Write(tempNode.data + " ");
                tempNode = tempNode.next;
            }
            Console.WriteLine();
        }

        //尾插法 按照输入数据的顺序插入到线性表中
        public Node<T> CreateNodeTail<T>(T[] datas)
        {
            //创建一个指向列表尾部结点的单链表
            Node<T> headNode = new Node<T>(); //头结点
            Node<T> tailNode = headNode; //尾节点
            headNode.next = tailNode;
            COUNT = 0;

            for (int i = 0; i < datas.Length; i++)
            {
                Node<T> newNode = new Node<T>(datas[i]);
                tailNode.next = newNode;
                tailNode = newNode;
                COUNT++;
            }
            tailNode.next = null;//遍历时用于确认到了尾部
            return headNode;
        }

        /// <summary>
        /// 获取指定i位置的数据
        /// </summary>
        /// <typeparam name="T">泛型</typeparam>
        /// <param name="head">链表头结点</param>
        /// <param name="i">链表第i个元素</param>
        /// <returns>返回链表第i个元素的数据域</returns>
        public T GetElem<T>(Node<T> head, int i)
        {
            int j = 0;
            T value;
            Node<T> tempNode = head.next;
            //迭代找到该位置
            while (tempNode != null && j < i)
            {
                tempNode = tempNode.next;
                ++j;
            }
            if (tempNode == null || j > i)
                return default(T);
            //取值操作
            value = tempNode.data;
            return value;
        }

        //向单链表的指定位置i，插入指定的元素
        public bool InsertElem<T>(Node<T> head, int i, T value)
        {
            int j = 1;
            Node<T> tempNode = head.next;
            //迭代找到待插入位置
            while (tempNode != null && j < i)
            {
                tempNode = tempNode.next;
                ++j;
            }
            if (tempNode == null || j > i)
                return false;
            //插入新节点操作
            Node<T> newNode = new Node<T>(value);
            //先牵右手再牵左手
            newNode.next = tempNode.next;
            tempNode.next = newNode;
            COUNT++;
            return true;
        }

        //删除链表的第i个结点，并返回删除的值
        public T DeleteElem<T>(Node<T> head, int i)
        {
            int j = 1;
            Node<T> tempNode = head.next, tempNextNode;
            while (tempNode != null && j < i)
            {
                tempNode = tempNode.next;
                ++j;
            }
            if (tempNode == null || j > i)
                return default(T);
            //删除结点操作
            tempNextNode = tempNode.next;
            tempNode.next = tempNextNode.next;
            T deleteElem = tempNextNode.data;
            COUNT--;
            return deleteElem;
        }
        //销毁线性表
        public bool DeleteLinkList<T>(Node<T> head)
        {
            bool flag = false;
            if (head != null)
            {
                head.next = null;
                flag = true;
            }
            COUNT = 0;
            return flag;
        }
    }
}
