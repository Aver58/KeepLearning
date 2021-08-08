// ������31��ջ��ѹ�롢��������
// ��Ŀ�����������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ���������
// ��Ϊ��ջ�ĵ���˳��
// ����ѹ��ջ���������־�����ȡ���������1��2��3��4��5��ĳջ��ѹջ���У�
// ����4��5��3��2��1�Ǹ�ѹջ���ж�Ӧ��һ���������У���4��3��5��1��2�Ͳ������Ǹ�ѹջ���еĵ������С�

#pragma once
#include <stack>
using namespace std;

class _31_StackPushPopOrder
{
	// �����һ������������ջ�����֣��͵���;
	// ����ջ����ѹջ��ֱ���ҵ���Ҫ�����֣����ȫ��ѹ�궼û���ҵ�������false
	bool IsPopOrder(const int* pPush, const int* pPop, int nLength)
	{
		if (pPush == nullptr || pPop == nullptr || nLength <= 0)
			return false;

		const int* pNextPush = pPush;
		const int* pNextPop = pPop;

		stack<int> stack;

		while (pNextPop - pPop < nLength)
		{
			// ������ջ��ջ��Ԫ�ز���Ҫ������Ԫ��
			// ��ѹ��һЩ������ջ
			while(stack.empty() || stack.top() != *pNextPop)
			{
				// ����������ֶ�ѹ�븨��ջ�ˣ��˳�ѭ��
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

