// ������24����ת����
// ��Ŀ������һ������������һ�������ͷ��㣬��ת�����������ת�������
// ͷ��㡣

#pragma once
#include <cstdio>
#include "Utilities\List.h"
class _24_ReverseList
{
	ListNode* ReverseList(ListNode* pHead)
	{
		if (pHead == nullptr)
			return nullptr;
		ListNode* pReversedHead = nullptr;
		ListNode* pPreNode = pHead;
		ListNode* pNode = pHead;

		while (pNode != nullptr)
		{
			ListNode* pNextNode = pNode->m_pNext;
			if (pNextNode == nullptr)
				pReversedHead = pNode;

			pNode->m_pNext = pPreNode;

			pPreNode = pNode;
			pNode = pNextNode;
		}

		return pReversedHead;
	}
};

