// 面试题22：链表中倒数第k个结点
// 题目：输入一个链表，输出该链表中倒数第k个结点。为了符合大多数人的习惯，
// 本题从1开始计数，即链表的尾结点是倒数第1个结点。例如一个链表有6个结点，
// 从头结点开始它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个结点是
// 值为4的结点。

#pragma once
#include <cstdio>
#include "Utilities\List.h"

class _22_KthNodeFromEnd
{
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
	{
		if (pListHead == nullptr || k <= 0)
			return nullptr;
	
		// 双指针【老牛拖车法】，快指针比慢指针快k个节点，当快指针到末尾的时候，慢指针就是要的值
		ListNode* pFast = pListHead;
		ListNode* pSlow = pListHead;
		int index = 0;
		while (pFast != nullptr)
		{
			pFast = pFast->m_pNext;
			index++;
			if (index >= k)
			{
				pSlow = pSlow->m_pNext;
			}
		}
		// 快指针还没走到k位置
		if (index < k)
			return nullptr;
		
		return pSlow;
	}
};

