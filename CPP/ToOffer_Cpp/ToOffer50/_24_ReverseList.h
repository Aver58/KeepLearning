// 面试题24：反转链表
// 题目：定义一个函数，输入一个链表的头结点，反转该链表并输出反转后链表的
// 头结点。

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

