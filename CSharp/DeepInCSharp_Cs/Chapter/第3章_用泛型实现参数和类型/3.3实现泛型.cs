using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DeepInCSharp.第3章_用泛型实现参数和类型
{
    class _实现泛型
    {

        static void Mains()//要用的时候改成Main
        {
            Console.WriteLine(CompareToDefault("X"));
            Console.WriteLine(CompareToDefault(1));
            Console.WriteLine(CompareToDefault(-1));
            Console.WriteLine(CompareToDefault(0));

            Console.Clear();

            string name = "Jon";
            string info1 = "My name is "+name;
            string info2 = "My name is "+name;

            Console.WriteLine(info1==info2);//true
            Console.WriteLine(AreReferencesEqual(info1,info2));//false

            Console.Clear();

            Pair<int, string> pair = new Pair<int, string>(10, "value");

            Console.ReadKey();
        }

        //表示一对值的泛型类、、不懂，先跳到3.5节//缺第3.4章，以后再补
        public sealed class Pair<T,U>:IEnumerable<Pair<T, U>>
        {
            private static readonly IEqualityComparer<T> firstComparer = EqualityComparer<T>.Default;
            private static readonly IEqualityComparer<U> secondComparer = EqualityComparer<U>.Default;
            public T First { get; }
            public U Second { get; }
            public Pair(T first,U second)
            {
                this.First = first;
                this.Second = second;
            }
            public bool Equal(Pair<T, U> other)
            {
                return other != null && firstComparer.Equals(this.First, other.First) &&
                                        secondComparer.Equals(this.Second, other.Second);
            }
            public override bool Equals(object obj)
            {
                return base.Equals(obj as Pair<T,U>);
            }
            public override int GetHashCode()
            {
                return firstComparer.GetHashCode(First) * 37 +
                        secondComparer.GetHashCode(Second);
            }

            IEnumerator<Pair<T, U>> IEnumerable<Pair<T, U>>.GetEnumerator()
            {
                throw new NotImplementedException();
            }

            IEnumerator IEnumerable.GetEnumerator()
            {
                throw new NotImplementedException();
            }
        }
        /// <summary>
        /// 引用比较
        /// </summary>
        /// <typeparam name="T"></typeparam>
        /// <param name="first"></param>
        /// <param name="second"></param>
        /// <returns></returns>
        static bool AreReferencesEqual<T>(T first, T second)
            where T : class
        {
            return first == second;
        }
        /// <summary>
        /// 跟默认值比对
        /// </summary>
        /// <typeparam name="T"></typeparam>
        /// <param name="value"></param>
        /// <returns></returns>
        static int CompareToDefault<T>(T value) where T : IComparable<T>
        {
            return value.CompareTo(default(T));
        }

        
    }
}
