// 面试题25：合并两个排序的链表
// 题目：输入两个递增排序的链表，合并这两个链表并使新链表中的结点仍然是按
// 照递增排序的。例如输入图3.11中的链表1和链表2，则合并之后的升序链表如链
// 表3所示。
#pragma once
#include <cstdio>
#include "Utilities\List.h"
class _25_MergeSortedLists
{
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		// 1. 迭代版
		//if (pHead1 == nullptr)
		//	return pHead2;
		//if (pHead2 == nullptr)
		//	return pHead1;

		//ListNode* p1 = pHead1;
		//ListNode* p2 = pHead2;
		//ListNode* pHead = p1->m_nValue > p2->m_nValue ? p2 : p1;
		//while (p1 != nullptr && p2 != nullptr)
		//{
		//	if (p1->m_nValue > p2->m_nValue)
		//	{
		//		ListNode* temp = p2->m_pNext;
		//		p2->m_pNext = p1;
		//		p2 = temp;
		//	}
		//	else
		//	{
		//		ListNode* temp = p1->m_pNext;
		//		p1->m_pNext = p2;
		//		p1 = temp;
		//	}
		//}
		//return pHead;

		// 2. 递归版
		if (pHead1 == nullptr)
			return pHead2;
		if (pHead2 == nullptr)
			return pHead1;

		ListNode* pMergeHead = nullptr;
		if (pHead1->m_nValue > pHead2->m_nValue)
		{
			pMergeHead = pHead2;
			pMergeHead->m_pNext = Merge(pHead1,pHead2->m_pNext);
		}
		else
		{
			pMergeHead = pHead1;
			pMergeHead->m_pNext = Merge(pHead1->m_pNext,pHead2);
		}
		return pMergeHead;
	}
    // ====================测试代码====================
    ListNode* Test(const char* testName, ListNode* pHead1, ListNode* pHead2)
    {
        if (testName != nullptr)
            printf("%s begins:\n", testName);

        printf("The first list is:\n");
        PrintList(pHead1);

        printf("The second list is:\n");
        PrintList(pHead2);

        printf("The merged list is:\n");
        ListNode* pMergedHead = Merge(pHead1, pHead2);
        PrintList(pMergedHead);

        printf("\n\n");

        return pMergedHead;
    }

    // list1: 1->3->5
    // list2: 2->4->6
    void Test1()
    {
        ListNode* pNode1 = CreateListNode(1);
        ListNode* pNode3 = CreateListNode(3);
        ListNode* pNode5 = CreateListNode(5);

        ConnectListNodes(pNode1, pNode3);
        ConnectListNodes(pNode3, pNode5);

        ListNode* pNode2 = CreateListNode(2);
        ListNode* pNode4 = CreateListNode(4);
        ListNode* pNode6 = CreateListNode(6);

        ConnectListNodes(pNode2, pNode4);
        ConnectListNodes(pNode4, pNode6);

        ListNode* pMergedHead = Test("Test1", pNode1, pNode2);

        DestroyList(pMergedHead);
    }

    // 两个链表中有重复的数字
    // list1: 1->3->5
    // list2: 1->3->5
    void Test2()
    {
        ListNode* pNode1 = CreateListNode(1);
        ListNode* pNode3 = CreateListNode(3);
        ListNode* pNode5 = CreateListNode(5);

        ConnectListNodes(pNode1, pNode3);
        ConnectListNodes(pNode3, pNode5);

        ListNode* pNode2 = CreateListNode(1);
        ListNode* pNode4 = CreateListNode(3);
        ListNode* pNode6 = CreateListNode(5);

        ConnectListNodes(pNode2, pNode4);
        ConnectListNodes(pNode4, pNode6);

        ListNode* pMergedHead = Test("Test2", pNode1, pNode2);

        DestroyList(pMergedHead);
    }

    // 两个链表都只有一个数字
    // list1: 1
    // list2: 2
    void Test3()
    {
        ListNode* pNode1 = CreateListNode(1);
        ListNode* pNode2 = CreateListNode(2);

        ListNode* pMergedHead = Test("Test3", pNode1, pNode2);

        DestroyList(pMergedHead);
    }

    // 一个链表为空链表
    // list1: 1->3->5
    // list2: 空链表
    void Test4()
    {
        ListNode* pNode1 = CreateListNode(1);
        ListNode* pNode3 = CreateListNode(3);
        ListNode* pNode5 = CreateListNode(5);

        ConnectListNodes(pNode1, pNode3);
        ConnectListNodes(pNode3, pNode5);

        ListNode* pMergedHead = Test("Test4", pNode1, nullptr);

        DestroyList(pMergedHead);
    }

    // 两个链表都为空链表
    // list1: 空链表
    // list2: 空链表
    void Test5()
    {
        ListNode* pMergedHead = Test("Test5", nullptr, nullptr);
    }

    int main()
    {
        Test1();
        Test2();
        Test3();
        Test4();
        Test5();

        return 0;
    }
};

