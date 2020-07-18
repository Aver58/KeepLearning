using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Algorithm
{
    class WeakReferenceClass
    {
        static void WeakReference()
        {
            //实例化成员就是强引用，本身被引用的次数+1.
            Object obj1 = new Object();
            //把对象的引用记录下来,
            //第二个参数给true，这个弱引用就是一个long weak reference（长弱引用）。
            //在对象的Finalize方法没有被执行以前，Target都可用。
            //不过这是对象的某些成员变量也许已经被回收，所以使 用起来要想当小心。
            WeakReference weakObj = new WeakReference(obj1,true);
            //释放掉对对象A的强引用。这时如果GC进行回收，对象A就会被回收。
            obj1 = null;

            if (weakObj.IsAlive)
            {
                //do someting
            }
            else
            {
                //new 一个实例
            }
        }

        //三：怎样使用弱引用

        //弱引用类： WeakReference //有两个重载的构造函数

        //WeakReference WeakObj=new WeakReference(Object);//弱引用方式

        //IsAlive属性是判断此弱引用对象所引用的对象是否还存在，存在：IsAlive=True;

        //Target属性是设置该弱引用对象所引用的数据对象的值

        //https://www.cnblogs.com/mokey/archive/2011/11/24/2261605.html
    }
}
