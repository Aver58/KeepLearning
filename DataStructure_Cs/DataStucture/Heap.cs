using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataStructure
{
    #region 堆的两个特性
    //   结构性 ：用数组表示的完全二叉树；
    // 有序性 ： 任一结点 的关键字是其子树所有结点的最大值(或最小值)
    //         “ 最大堆(MaxHeap) ”, 也称“ 大顶堆 ”：最大值
    //         “ 最小堆(MinHeap) ”, 也称“ 小顶堆 ” 
    #endregion
    public interface IHeap
    {
        int GetLength();
        bool IsEmpty();
        bool IsFull();
        void Clear();
        //Node<T> Find(int i);
        //int Index(T node);
        //void Add(T item);
        //void Delete(int i);
        void Insert(int data);
        //void Reverse();
    }

    abstract class HeapBase: IHeap
    {
        public int[] items { get; set; }
        private int m_capacity;
        public int size { get; set; }
        public HeapBase(int maxSize)
        {
            items[0] = 1000; //从1开始，0设置成哨兵
            m_capacity = maxSize;
            size++;
        }

        public int GetLength()
        {
            return size;
        }

        public bool IsEmpty()
        {
            return size == 0;
        }

        public bool IsFull()
        {
            return size >= m_capacity;
        }

        public abstract void Insert(int data);
        public abstract void Delete();
        public abstract void Clear();
    }

    //最大堆
    class MaxHeap : HeapBase
    {
        public MaxHeap(int value) : base(value)
        {
        }

        public override void Insert(int item)
        {
            if (IsFull())
            {
                Console.WriteLine("IsFull!!");
                return;
            }
            int i = size;
            for (; (item > items[i / 2])||(item < items[0]); i/=2)//奇数的问题
            {
                items[i] = items[i / 2];
            }
            items[i] = item;
        }

        //最大堆的删除操作，总是从堆的根结点删除元素。
        //对于最大堆的删除，我们不能自己进行选择删除某一个结点，我们只能删除堆的根结点
        public override void Delete()
        {
            if (IsEmpty())
            {
                Console.WriteLine("IsEmpty!!");
                return;
            }
            int parent, child;
            var temp = items[1];
            for (parent = 1; parent * 2 < size; parent = child)
            {
                child = parent * 2;
                if (items[child] < items[child + 1])
                    child++;
                if (temp >= items[child]) break;
                else
                {
                    items[parent] = items[child];
                }
            }
            items[parent] = temp;
        }

        public override void Clear()
        {
            throw new NotImplementedException();
        }
    }
    //class MinHeap : HeapBase
    //{
    //    //最小堆
    //}
}
