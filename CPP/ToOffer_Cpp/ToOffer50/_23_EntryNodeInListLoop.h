// 面试题23：链表中环的入口结点
// 题目：一个链表中包含环，如何找出环的入口结点？例如，在图3.8的链表中，
// 环的入口结点是结点3。

#pragma once
#include "Utilities/list.h"

class _23_EntryNodeInListLoop
{
	// ①快慢指针，当2指针相遇的时候就证明是个环
	// ②双指针，p1在头结点，如果链表的环有n个节点，p2就先向前移动n步，然后2个相同速度移动，相遇的时候就是入口
	// ③链表的环的节点数：从相遇点①开始计数，再次回到相遇点的时候，就能拿到节点数
	
	// 找到相遇点
	ListNode* MeetingNode(ListNode* pHead)
	{
		if (pHead == nullptr)
			return nullptr;

		ListNode* pSlow = pHead->m_pNext;
		if (pSlow == nullptr)
			return nullptr;

		ListNode* pFast = pSlow->m_pNext;
		while (pFast!=nullptr && pSlow != nullptr)
		{
			if (pFast == pSlow)
				return pFast;

			pSlow = pSlow->m_pNext;
			pFast = pFast->m_pNext;
			if (pFast != nullptr)
				pFast = pFast->m_pNext;
		}
		return nullptr;
	}

	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		//①快慢指针，当2指针相遇的时候就证明是个环
		ListNode* pMeet = MeetingNode(pHead);
		if (pMeet == nullptr)
			return nullptr;
		// ③链表的环的节点数：从相遇点①开始计数，再次回到相遇点的时候，就能拿到节点数
		int loopCount = 1;
		while (pMeet != nullptr)
		{
			loopCount++;
			pMeet = pMeet->m_pNext;
		}

		// ②双指针，p1在头结点，如果链表的环有n个节点，p2就先向前移动n步，然后2个相同速度移动，相遇的时候就是入口
		ListNode* pSlow = pHead;
		ListNode* pFast = pHead;
		while (pFast != nullptr && loopCount > 0)
		{
			pFast = pFast->m_pNext;
			loopCount--;
		}

		while (pFast != nullptr && pSlow != nullptr)
		{
			if (pFast == pSlow)
				return pFast;

			pSlow = pSlow->m_pNext;
			pFast = pFast->m_pNext;
		}
		return pFast;
	}
};

