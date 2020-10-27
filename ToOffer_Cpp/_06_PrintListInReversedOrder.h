#pragma once

#include <stack>
#include "Utilities/List.h"

class _06_PrintListInReversedOrder
{
public:
	// 从尾到头打印链表
	// 题目：输入一个链表的头结点，从尾到头反过来打印出每个结点的值。

	//1. 使用栈进行遍历
	void PrintListReversingly_Iteratively(ListNode* pHead)
	{
		std::stack<ListNode*> nodes;
		ListNode* pNode = pHead;
		while (pNode != nullptr)
		{
			nodes.push(pNode);
			pNode = pNode->m_pNext;
		}

		while (!nodes.empty())
		{
			pNode = nodes.top();
			printf("%d\t", pNode->m_nValue);
			nodes.pop();
		}
	}

	//2. 递归 : 有个问题，当链表非常长，调用堆栈太深导致调用栈溢出，所以方法1比较好
	void PrintListReversingly_Recursively(ListNode* pHead)
	{
		ListNode* pNode = pHead;
		if (pNode != nullptr)
		{
			if (pNode->m_pNext != nullptr)
			{
				PrintListReversingly_Recursively(pNode->m_pNext);
			}

			printf("%d\t", pNode->m_nValue);
		}
	}

	void Test(ListNode* pHead)
	{
		PrintList(pHead);
		PrintListReversingly_Iteratively(pHead);
		printf("\n");
		PrintListReversingly_Recursively(pHead);
	}

	// 1->2->3->4->5
	void Test1()
	{
		printf("\nTest1 begins.\n");

		ListNode* pNode1 = CreateListNode(1);
		ListNode* pNode2 = CreateListNode(2);
		ListNode* pNode3 = CreateListNode(3);
		ListNode* pNode4 = CreateListNode(4);
		ListNode* pNode5 = CreateListNode(5);

		ConnectListNodes(pNode1, pNode2);
		ConnectListNodes(pNode2, pNode3);
		ConnectListNodes(pNode3, pNode4);
		ConnectListNodes(pNode4, pNode5);

		Test(pNode1);

		DestroyList(pNode1);
	}

	// 只有一个结点的链表: 1
	void Test2()
	{
		printf("\nTest2 begins.\n");

		ListNode* pNode1 = CreateListNode(1);

		Test(pNode1);

		DestroyList(pNode1);
	}

	// 空链表
	void Test3()
	{
		printf("\nTest3 begins.\n");

		Test(nullptr);
	}
};