using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Algorithm.ToOffer
{
    // 面试题2.实现单例

    //public 修饰符，保证它们能被访问到
    //sealed 修饰符，保证它们不能作为其他类型的基类

    /// <summary>
    /// 最基础的单例，但是只能在单线程中使用
    /// </summary>
    public sealed class Singleton0
    {
        public Singleton0() { }

        private static Singleton0 m_instance;
        public Singleton0 Instance {
            get {
                if (m_instance == null)
                    m_instance = new Singleton0();
                return m_instance;
            }
        }
    }
    /// <summary>
    /// 多线程中可使用的单例，但是同步锁比较耗时
    /// </summary>
    public sealed class SingletonMuliti
    {
        public SingletonMuliti() { }

        private static SingletonMuliti m_instance;
        // 设置一个同步锁
        private static readonly object syncObj;
        public SingletonMuliti Instance
        {
            get
            {
                //加锁非常耗时
                lock (syncObj)
                {
                    if (m_instance == null)
                        m_instance = new SingletonMuliti();
                }
                return m_instance;
            }
        }
    }

    /// <summary>
    /// 改进后的多线程同步锁，在加锁前后都判断一下空
    /// </summary>
    public sealed class SingletonMuliti2
    {
        public SingletonMuliti2() { }

        private static SingletonMuliti2 m_instance;
        private static readonly object syncObj;
        public SingletonMuliti2 Instance
        {
            get
            {
                //加锁前判断实例是否存在
                if (m_instance == null)
                {
                    lock (syncObj)
                    {
                        if (m_instance == null)
                            m_instance = new SingletonMuliti2();
                    }
                }
                return m_instance;
            }
        }
    }

    /// <summary>
    /// 静态构造单例，但可能过早创建
    /// </summary>
    public sealed class SingletonStatic
    {
        public SingletonStatic() { }
        //在初始化静态变量的时候创建一个实例。而且静态构造函数只会调用一次。
        //但是静态构造函数不受程序员控制，它是在CLR第一次使用这个类型时候自动构造的。
        //这样可能实例会过早地创建，影响效率
        private static SingletonStatic m_instance = new SingletonStatic();
        public SingletonStatic Instance
        {
            get
            {
                return m_instance;
            }
        }
    }

    /// <summary>
    /// 按需静态构造单例，嵌套构造函数
    /// </summary>
    public sealed class SingletonStaticInNeed
    {
        public SingletonStaticInNeed() { }
        public SingletonStaticInNeed Instance
        {
            get
            {
                return Nest.instance;
            }
        }

        private class Nest
        {
            static internal SingletonStaticInNeed instance = new SingletonStaticInNeed();
        }
    }

    /// <summary>
    /// 干净的写法，项目中用的
    /// </summary>
    public sealed class Singleton
    {
        public Singleton() { }
        private static Singleton m_instance;
        public Singleton Instance
        {
            get
            {
                return m_instance ?? (m_instance = new Singleton());
            }
        }
    }

    //要求定义一个表示总体的类President，
    //可以从这个类继承出FrenchPresident和AmericanPresident等类型，
    //这些派生类都只能产生一个实例。

    public class President
    {
        public President() { }
        private static President m_instance;
        public President Instance
        {
            get
            {
                return m_instance ?? (m_instance = new President());
            }
        }
    }

    public sealed class FrenchPresident : President
    {
       
    }

    public sealed class AmericanPresident : President
    {

    }
}
