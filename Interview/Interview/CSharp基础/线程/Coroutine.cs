#region Copyright © 2020 Aver. All rights reserved.
/*
=====================================================
 AverFrameWork v1.0
 Filename:    Coroutine.cs
 Author:      Zeng Zhiwei
 Time:        2021\3\14 星期日 23:02:09
=====================================================
*/
#endregion

using System;
using System.Collections;

namespace TestCoroutine
{
    /// <summary>
    /// 协程类定义
    /// </summary>
    public sealed class Coroutine
    {
        private IEnumerator _routine;
        public Coroutine(IEnumerator routine)
        {
            _routine = routine;
        }

        public bool MoveNext()
        {
            if(_routine == null)
                return false;

            //看迭代器当前的流程控制（即yield return 后边的对象）
            //是否是我们当前IWait对象，如果是，看是否满足moveNext的条件
            IWait wait = _routine.Current as IWait;
            bool moveNext = true;
            if(wait != null)
                moveNext = wait.Tick();

            if(!moveNext)
            {
                //此处有些不好理解。当时间没有到时，我们应该返回true
                //告诉管理器我们后边还有对象需要下一次继续迭代
                Console.WriteLine("[Coroutine] not move next");
                return true;
            }
            else
            {
                //此时所有等待时间或者帧都已经迭代完毕，看IEnumerator对象后续是否还有yield return对象
                //将此结果通知给管理器，管理器会在下一次迭代时决定是否继续迭代该Coroutine对象
                Console.WriteLine("[Coroutine] move next");
                return _routine.MoveNext();
            }
        }

        public void Stop()
        {
            _routine = null;
        }
    }
}