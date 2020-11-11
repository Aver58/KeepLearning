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
using System.Collections.Generic;

public class List<T>
{
    private const int _defaultCapacity = 4;
    private T[] _items;
    private int _size;
    static readonly T[] _emptyArray = new T[0];

    public List()
    {
        _items = _emptyArray;
    }

    public List(int capacity)
    {
        if(capacity < 0)
        {
            return;
        }

        if(capacity == 0)
            _items = _emptyArray;
        else
            _items = new T[capacity];
    }

    public List(IEnumerable<T> collection)
    {
        if(collection == null)
            throw new ArgumentNullException(collection.ToString());


    }
    //public T this[int index]
    //{
    //    get;
    //    set;
    //}

    //int IndexOf(T item);

    // Inserts value into the list at position index.
    //void Insert(int index, T item);

    // Removes the item at position index.
    //void RemoveAt(int index);
}