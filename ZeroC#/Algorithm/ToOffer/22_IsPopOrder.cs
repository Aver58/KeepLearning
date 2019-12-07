#region Copyright © 2018 Aver. All rights reserved.
/*
=====================================================
 AverFrameWork v1.0
 Filename:    _22_IsPopOrder.cs
 Author:      Zeng Zhiwei
 Time:        2018/12/21 13:44:29
=====================================================
*/
#endregion

using System;
using System.Collections.Generic;

public class _22_IsPopOrder
{

    // 判断一个序列是不是栈的弹出序列：
    // 如果下一个数字刚好是栈顶元素，直接弹出
    // 不是的话，把未入栈的压入，直到栈顶元素是下一个数字，
    // 如果到最后都没有找到数字，那就说明不是。

    // pushList为输入元素的头指针, 例如1,2,3,4,5
    // popList为弹出序列的头指针,例如4,5,3,2,1,
    bool IsPopOrder(List<int> pushList, List<int> popList)
    {
        if(pushList == null || popList == null
            || pushList.Count != pushList.Count
            || pushList.Count == 0|| popList.Count == 0)
            return false;

        bool bPossible = false;
        int pushPointer = 0;
        Stack<int> tempStack = new Stack<int>();
        for(int i = 0; i < popList.Count; i++)
        {
            int curInt = popList[i];
            if(curInt == pushList[pushPointer])
            {
                pushPointer++;
                continue;
            }
            else
            {
                while(tempStack!=null 
                    && pushPointer < pushList.Count 
                    && curInt!= tempStack.Peek())
                {
                    if(curInt == pushList[pushPointer])
                        break;

                    tempStack.Push(pushList[pushPointer]);
                    pushPointer++;
                }
            }
        }

    }

    class Program
    {
        static void Main()
        {

            Console.ReadLine();
        }
    }
}

