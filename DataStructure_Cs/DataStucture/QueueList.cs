using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataStructure
{
    public interface IQueueList<T>
    {
        int GetLength();
        bool IsEmpty();
        bool IsFull();
        void Insert(T node, int i);
        void Add(T node);
        void Delete(int i);
        void Clear();
        int Find(T node);
        void Reverse();
    }
    /// <summary>
    /// 队列
    /// </summary>
    /// <typeparam name="T"></typeparam>
    class QueueList<T> : IQueueList<T>
    {
        private int m_front;
        private int m_rear;
        private int m_size;
        private T[] m_Items;

        public QueueList(int size)
        {
            m_Items = new T[size];
            m_front = m_rear = -1;
            m_size = size;
        }

        public void Add(T node)
        {
            if (IsFull())
            {
                Console.WriteLine("This list is full! Can't Add any new items!");
                return;
            }
            m_rear++;
            m_Items[m_rear] = node;
        }

        public void Clear()
        {
            m_Items = new T[m_size];
            m_front = m_rear = -1;
        }

        public void Delete(int i)
        {
            if (IsEmpty())
            {
                Console.WriteLine("This list is empty!");
                return;
            }
            m_Items[m_rear] = default(T);
            m_rear--;
        }

        public int Find(T node)
        {
            if (IsEmpty())
            {
                Console.WriteLine("This list is empty!");
                return -1;
            }
            for (int i = 0; i < m_Items.Length; i++)
            {
                if (m_Items[i].Equals(node))
                {
                    return i;
                }
            }
            Console.WriteLine("No Find The Item!");
            return -1;
        }

        public int GetLength()
        {
            return (m_front + 1)%m_size;
        }

        public void Insert(T node, int i)
        {
            if (IsFull())
            {
                Console.WriteLine("This list is full! Can't Add any new items!");
                return;
            }
            m_rear++;
            m_Items[m_rear] = node;
        }

        public bool IsEmpty()
        {
            return m_rear == m_front;
        }

        public bool IsFull()
        {
            return (m_rear + 1) % m_size == m_front;
        }

        public void Reverse()
        {
            if (IsEmpty())
            {
                Console.WriteLine("This list is empty!");
                return;
            }
            for (int i = 0; i < m_Items.Length/2; i++)
            {
                var temp = m_Items[m_rear];
                m_Items[m_rear] = m_Items[m_front];
                m_Items[m_front] = temp;
            }
        }
    }
}
