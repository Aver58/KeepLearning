#region Copyright © 2020 Aver. All rights reserved.
/*
=====================================================
 AverFrameWork v1.0
 Filename:    Hashtable.cs
 Author:      Zeng Zhiwei
 Time:        2020\11\12 星期四 22:53:41
=====================================================
*/
#endregion

using System;
using System.Collections;
using System.Diagnostics;

public class Hashtable
{
    internal const Int32 HashPrime = 101;

    
    
}

internal static class HashHelpers
{
    // This is the maximum prime smaller than Array.MaxArrayLength
    public const int MaxPrimeArrayLength = 0x7FEFFFFD;

    public const int HashCollisionThreshold = 100;

    /// <summary>
    /// 用于取哈希表的长度的表
    /// 传统扩容长度算法会取一个比之前2倍容量大的最小素数
    /// 假设我们当前容量为x，添加足量元素导致扩容，
    /// </summary>
    // Table of prime numbers to use as hash table sizes. 
    // A typical resize algorithm would pick the smallest prime number in this array
    // that is larger than twice the previous capacity. 
    // Suppose our Hashtable currently has capacity x and enough elements are added 
    // such that a resize needs to occur. Resizing first computes 2x then finds the 
    // first prime in the table greater than 2x, i.e. if primes are ordered 
    // p_1, p_2, ..., p_i, ..., it finds p_n such that p_n-1 < 2x < p_n. 
    // Doubling is important for preserving the asymptotic complexity of the 
    // hashtable operations such as add.  Having a prime guarantees that double 
    // hashing does not lead to infinite loops.  IE, your hash function will be 
    // h1(key) + i*h2(key), 0 <= i < size.  h2 and the size must be relatively prime.
    public static readonly int[] primes = {
            3, 7, 11, 17, 23, 29, 37, 47, 59, 71, 89, 107, 131, 163, 197, 239, 293, 353, 431, 521, 631, 761, 919,
            1103, 1327, 1597, 1931, 2333, 2801, 3371, 4049, 4861, 5839, 7013, 8419, 10103, 12143, 14591,
            17519, 21023, 25229, 30293, 36353, 43627, 52361, 62851, 75431, 90523, 108631, 130363, 156437,
            187751, 225307, 270371, 324449, 389357, 467237, 560689, 672827, 807403, 968897, 1162687, 1395263,
            1674319, 2009191, 2411033, 2893249, 3471899, 4166287, 4999559, 5999471, 7199369};

    public static int GetPrime(int min)
    {
        if(min < 0)
            throw new ArgumentException();

        for(int i = 0; i < primes.Length; i++)
        {
            int prime = primes[i];
            if(prime >= min) return prime;
        }

        //如果超出预先的数组
        for(int i = (min | 1); i < Int32.MaxValue; i += 2)
        {
            if(IsPrime(i) && ((i - 1) % Hashtable.HashPrime != 0))
                return i;
        }
        return min;
    }

    /// <summary>
    /// 是否是素数
    /// </summary>
    public static bool IsPrime(int candidate)
    {
        if((candidate & 1) != 0)
        {
            int limit = (int)Math.Sqrt(candidate);
            for(int divisor = 3; divisor <= limit; divisor += 2)
            {
                if((candidate % divisor) == 0)
                    return false;
            }
            return true;
        }
        return (candidate == 2);
    }

    // Returns size of hashtable to grow to.
    public static int ExpandPrime(int oldSize)
    {
        int newSize = 2 * oldSize;

        // Allow the hashtables to grow to maximum possible size (~2G elements) before encoutering capacity overflow.
        // Note that this check works even when _items.Length overflowed thanks to the (uint) cast
        if((uint)newSize > MaxPrimeArrayLength && MaxPrimeArrayLength > oldSize)
        {
            Debug.Assert(MaxPrimeArrayLength == GetPrime(MaxPrimeArrayLength));
            return MaxPrimeArrayLength;
        }

        return GetPrime(newSize);
    }

    public static bool IsWellKnownEqualityComparer(object comparer)
    {
        return (comparer == null || comparer == System.Collections.Generic.EqualityComparer<string>.Default || comparer is IWellKnownStringEqualityComparer);
    }

    // This interface is implemented by string comparers in the framework that can opt into
    // randomized hashing behaviors.
    internal interface IWellKnownStringEqualityComparer
    {
        // Get an IEqualityComparer that has the same equality comparision rules as "this" but uses Randomized Hashing.
        IEqualityComparer GetRandomizedEqualityComparer();
        // Get an IEqaulityComparer that can be serailzied (e.g., it exists in older versions).
        IEqualityComparer GetEqualityComparerForSerialization();
    }
}