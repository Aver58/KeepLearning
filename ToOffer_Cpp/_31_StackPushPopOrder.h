// 面试题31：栈的压入、弹出序列
// 题目：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是
// 否为该栈的弹出顺序。
// 假设压入栈的所有数字均不相等。例如序列1、2、3、4、5是某栈的压栈序列，
// 序列4、5、3、2、1是该压栈序列对应的一个弹出序列，但4、3、5、1、2就不可能是该压栈序列的弹出序列。

#pragma once
#include <stack>
using namespace std;

class _31_StackPushPopOrder
{
	// 如果下一个弹出数字是栈顶数字，就弹出;
	// 不在栈顶，压栈，直到找到需要的数字，如果全部压完都没有找到，返回false
	bool IsPopOrder(const int* pPush, const int* pPop, int nLength)
	{
		if (pPush == nullptr || pPop == nullptr || nLength <= 0)
			return false;

		const int* pNextPush = pPush;
		const int* pNextPop = pPop;

		stack<int> stack;

		while (pNextPop - pPop < nLength)
		{
			// 当辅助栈的栈顶元素不是要弹出的元素
			// 先压入一些数字入栈
			while(stack.empty() || stack.top() != *pNextPop)
			{
				// 如果所有数字都压入辅助栈了，退出循环
				if (pNextPush - pPush == nLength)
					break;

				stack.push(*pNextPush);
				pNextPush++;
			}
			if (stack.top() == *pNextPop)
			{
				stack.pop();
				pNextPop++;
			}
		}
		if (stack.empty() && pNextPop - pPop == nLength)
			return true;

		return false;
	}
};

