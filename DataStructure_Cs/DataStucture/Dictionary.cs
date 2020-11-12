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
        public Dictionary() : this(0, null) { }

        public Dictionary(int capacity, IEqualityComparer<TKey> comparer)
        {
            if(capacity < 0) throw new ArgumentOutOfRangeException();
            if(capacity > 0) Initialize(capacity);
            this.comparer = comparer ?? EqualityComparer<TKey>.Default;
        }

        private void Initialize(int capacity)
        {
            // 为啥C#源码的 HashHelpers 不用using
            int size = Hashtable.HashHelpers.GetPrime(capacity);
            buckets = new int[size];
            for(int i = 0; i < buckets.Length; i++) buckets[i] = -1;
            entries = new Entry[size];
            freeList = -1;
        }
    }
}