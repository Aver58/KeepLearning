using System;
using System.Collections;

namespace DeepInCSharp.第6章_迭代器
{
    class _1手写迭代器的痛苦
    {
        //IEnumerable 
        //IEnumerator
       
        static void Mains()//要用的时候改成Main
        {
            object[] values = { "a", "b", "c", "d", "e" };
            IterationSample collection = new IterationSample(values, 3);
            foreach (var item in collection)
            {
                Console.WriteLine(item);
            }
            Console.ReadKey();
        }
    }


    /// <summary>
    /// 新集合类型的框架
    /// </summary>
    class IterationSample : IEnumerable
    {
        public object[] values;
        public int startingPoint;

        public IterationSample(object[] value, int StartingPoint)
        {
            this.values = value;
            this.startingPoint = StartingPoint;
        }
        IEnumerator IEnumerable.GetEnumerator()
        {
            //C#1
            //return new IterationSampleIterator(this);
            //C#2 yield return  迭代器块中不允许包含普通return。只能是yield return
            for (int i = 0; i < values.Length; i++)
            {
                yield return values[ (i + startingPoint) % values.Length ];
            }
        }
    }

    /// <summary>
    /// 嵌套类实现集合迭代器
    /// </summary>
    class IterationSampleIterator : IEnumerator
    {
        IterationSample parent; //正在迭代的集合
        int position;           //遍历到的位置

        internal IterationSampleIterator(IterationSample parent)//internal？
        {
            this.parent = parent;
            position = -1;//在第一个元素开始之前开始
        }

        bool IEnumerator.MoveNext()
        {
            if (position != parent.values.Length)//如歌仍要遍历，那么增加position
            {
                position++;
            }
            return position < parent.values.Length;
        }

        object IEnumerator.Current
        {
            get
            {
                if (position == -1||position == parent.values.Length)//防止访问第一个元素之前的最后一个元素之后
                {
                    throw new InvalidOperationException();
                }
                int index = position + parent.startingPoint;
                index = index % parent.values.Length;
                return parent.values[index];//实现封装
            }
        }

        void IEnumerator.Reset()
        {
            position = -1;//返回第一个元素之前
        }
    }
}
