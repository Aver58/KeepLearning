#region Copyright © 2020 Aver. All rights reserved.
/*
=====================================================
 AverFrameWork v1.0
 Filename:    List.cs
 Author:      Zeng Zhiwei
 Time:        2020\11\11 星期三 23:53:02
=====================================================
*/
#endregion

using System;

namespace MyNamespace
{
    public class List<T>
    {
        private int _size;
        private T[] _items;
        /// <summary>
        /// 每次修改，值++，用来防止遍历中，被修改
        /// </summary>
        private int _version;
        private const int _defaultCapacity = 4;
        static readonly T[] _emptyArray = new T[0];
        internal const int MaxArrayLength = 0X7FEFFFFF;

        public List()
        {
            _items = _emptyArray;
        }

        public List(int capacity)
        {
            if(capacity < 0)
                throw new IndexOutOfRangeException();

            if(capacity == 0)
                _items = _emptyArray;
            else
                _items = new T[capacity];
        }

        public int Capacity
        {
            get
            {
                return _items.Length;
            }
            set
            {
                // 扩容
                if(value != _items.Length)
                {
                    if(value > 0)
                    {
                        T[] newItems = new T[value];
                        // 将旧内容复制到新的地址
                        if(_size > 0)
                            Array.Copy(_items, 0, newItems, 0, _size);
                        _items = newItems;
                    }
                    else
                    {
                        _items = _emptyArray;
                    }
                }
            }
        }

        public int Count
        {
            get
            {
                return _size;
            }
        }

        public T this[int index]
        {
            get
            {
                if(index >= _size)
                    throw new IndexOutOfRangeException();
                return _items[index];
            }
            set
            {
                if(index >= _size)
                    throw new IndexOutOfRangeException();
                _items[index] = value;
                _version++;
            }
        }

        int IndexOf(T item)
        {
            if(item == null)
                throw new NullReferenceException();
            for(int i = 0; i < _size; i++)
            {
                if(Equals(_items[i], item))
                    return i;
            }
            return -1;
        }

        void RemoveAt(int index)
        {
            if(index >= _size)
                throw new IndexOutOfRangeException();

            _size--;
            // 将指定索引后面的item向前移动1个位置
            if(index < _size)
            {
                Array.Copy(_items, index + 1, _items, index, _size - index);
            }
            // 最后一个值置空
            _items[_size] = default(T);
            _version++;
        }

        public void Add(T item)
        {
            if(_size == _items.Length) EnsureCapacity(_size + 1);
            _items[_size++] = item;
            _version++;
        }

        public void Insert(int index, T item)
        {
            if(index > _size)
                throw new IndexOutOfRangeException();
            if(_size == _items.Length) EnsureCapacity(_size + 1);
            if(index < _size)
                Array.Copy(_items, index, _items, index + 1, _size - index);
            _items[index] = item;
            _size++;
            _version++;
        }

        public bool Remove(T item)
        {
            int index = IndexOf(item);
            if(index != -1)
            {
                RemoveAt(index);
                return true;
            }
            return false;
        }

        // Ensures that the capacity of this list is at least the given minimum
        // value. If the currect capacity of the list is less than min, the
        // capacity is increased to twice the current capacity or to min,
        // whichever is larger.
        private void EnsureCapacity(int min)
        {
            if(_items.Length < min)
            {
                int newCapacity = _items.Length == 0 ? _defaultCapacity : _items.Length * 2;
                if((uint)newCapacity > MaxArrayLength) newCapacity = MaxArrayLength;
                if(newCapacity < min) newCapacity = min;
                Capacity = newCapacity;
            }
        }

        public void Clear()
        {
            if(_size > 0)
            {
                Array.Clear(_items, 0, _size);
                _size = 0;
                _version++;
            }
        }

        public bool Contains(T item)
        {
            int index = IndexOf(item);
            return index != -1;
        }

        public void Reverse()
        {
            Array.Reverse(_items, 0, Count);
            _version++;
        }

        public void Sort()
        {

        }

        #region Enumerator

        public Enumerator GetEnumerator()
        {
            return new Enumerator(this);
        }

        public struct Enumerator
        {
            private List<T> list;
            private int index;
            private int version;
            private T current;

            internal Enumerator(List<T> list)
            {
                this.list = list;
                index = 0;
                version = list._version;
                current = default(T);
            }

            public void Dispose() { }

            public bool MoveNext()
            {

                List<T> localList = list;

                if(((uint)index < (uint)localList._size))
                {
                    current = localList._items[index];
                    index++;
                    return true;
                }
                return MoveNextRare();
            }

            private bool MoveNextRare()
            {
                if(version != list._version)
                {
                    throw new Exception("version not matching!");
                }

                index = list._size + 1;
                current = default(T);
                return false;
            }

            public T Current
            {
                get
                {
                    return current;
                }
            }

            void Reset()
            {
                index = 0;
                current = default(T);
            }

        }
        #endregion

    }
}

