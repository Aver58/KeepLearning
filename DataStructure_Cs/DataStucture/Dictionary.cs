#region Copyright © 2020 Aver. All rights reserved.
/*
=====================================================
 AverFrameWork v1.0
 Filename:    Dictionary.cs
 Author:      Zeng Zhiwei
 Time:        2020\11\12 星期四 22:37:09
=====================================================
*/
#endregion


using System;
using System.Collections.Generic;

namespace MyNamespace
{
    public class Dictionary<TKey, TValue>
    {
        private struct Entry
        {
            public int hashCode;    // Lower 31 bits of hash code, -1 if unused
            public int next;        // Index of next entry, -1 if last
            public TKey key;        // Key of entry
            public TValue value;    // Value of entry
        }

        private int[] buckets;
        private Entry[] entries;
        private int count;
        private int version;
        private int freeList;
        private int freeCount;
        //private KeyCollection keys;
        //private ValueCollection values;
        private IEqualityComparer<TKey> comparer;

        public Dictionary() : this(0) { }

        public Dictionary(int capacity)
        {
            if(capacity < 0) throw new ArgumentOutOfRangeException();
            if(capacity > 0) Initialize(capacity);
        }

        #region private
        private void Initialize(int capacity)
        {
            int size = HashHelpers.GetPrime(capacity);
            buckets = new int[size];
            for(int i = 0; i < buckets.Length; i++)
                buckets[i] = -1;
            entries = new Entry[size];
            freeList = -1;
        }

        private void Insert(TKey key, TValue value, bool add)
        {
            if(key == null)
                throw new ArgumentNullException();
            if(buckets == null) Initialize(0);
            int hashCode = comparer.GetHashCode(key) & 0x7FFFFFFF;
            int targetBucket = hashCode % buckets.Length;

            for(int i = buckets[targetBucket]; i >= 0; i = entries[i].next)
            {
                if(entries[i].hashCode == hashCode && comparer.Equals(entries[i].key, key))
                {
                    if(add)
                        throw new ArgumentException("Argument_AddingDuplicate");
                    
                    entries[i].value = value;
                    version++;
                    return;
                }
            }

            int index;
            if(freeCount > 0)
            {
                index = freeList;
                freeList = entries[index].next;
                freeCount--;
            }
            else
            {
                if(count == entries.Length)
                {
                    Resize();
                    targetBucket = hashCode % buckets.Length;
                }
                index = count;
                count++;
            }


            entries[index].hashCode = hashCode;
            entries[index].next = buckets[targetBucket];
            entries[index].key = key;
            entries[index].value = value;
            buckets[targetBucket] = index;
            version++;

            //if(collisionCount > HashHelpers.HashCollisionThreshold && HashHelpers.IsWellKnownEqualityComparer(comparer))
            //{
            //    comparer = (IEqualityComparer<TKey>)HashHelpers.GetRandomizedEqualityComparer(comparer);
            //    Resize(entries.Length, true);
            //}
        }
        #endregion

        #region public

        public TValue this[TKey key] { get; set; }
        //public ValueCollection Values { get; }
        //public KeyCollection Keys { get; }
        public int Count { get; }
        public void Add(TKey key, TValue value)
        {

        }
        public void Clear();
        public bool ContainsKey(TKey key);
        public bool ContainsValue(TValue value);
        public bool Remove(TKey key);
        public bool TryGetValue(TKey key, out TValue value);
        #endregion
 


        #region Enumerator

        public Enumerator GetEnumerator()
        {
            return new Enumerator(this);
        }

        public struct Enumerator
        {
            //private List<T> list;
            //private int index;
            //private int version;
            //private T current;

            internal Enumerator()
            {
               
            }

            public void Dispose() { }

            public bool MoveNext()
            {
            
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
            }

        }

        #endregion
    }
}