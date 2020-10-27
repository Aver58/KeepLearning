// ������22�������е�����k�����
// ��Ŀ������һ����������������е�����k����㡣Ϊ�˷��ϴ�����˵�ϰ�ߣ�
// �����1��ʼ�������������β����ǵ�����1����㡣����һ��������6����㣬
// ��ͷ��㿪ʼ���ǵ�ֵ������1��2��3��4��5��6���������ĵ�����3�������
// ֵΪ4�Ľ�㡣

#pragma once
#include <cstdio>
#include "Utilities\List.h"

class _22_KthNodeFromEnd
{
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
	{
        // �Լ�д��
		//if (pListHead == nullptr || k <= 0)
		//	return nullptr;
	
		//// ˫ָ�롾��ţ�ϳ���������ָ�����ָ���k���ڵ㣬����ָ�뵽ĩβ��ʱ����ָ�����Ҫ��ֵ
		//ListNode* pFast = pListHead;
		//ListNode* pSlow = pListHead;
		//int index = 0;
		//while (pFast != nullptr)
		//{
		//	pFast = pFast->m_pNext;
		//	index++;
		//	if (index >= k)
		//	{
		//		pSlow = pSlow->m_pNext;
		//	}
		//}
		//// ��ָ�뻹û�ߵ�kλ��
		//if (index < k)
		//	return nullptr;
		
		//return pSlow;

        if (pListHead == nullptr || k == 0)
            return nullptr;

        ListNode* pAhead = pListHead;
        ListNode* pBehind = nullptr;

        for (unsigned int i = 0; i < k - 1; ++i)
        {
            if (pAhead->m_pNext != nullptr)
                pAhead = pAhead->m_pNext;
            else
            {
                return nullptr;
            }
        }

        pBehind = pListHead;
        while (pAhead->m_pNext != nullptr)
        {
            pAhead = pAhead->m_pNext;
            pBehind = pBehind->m_pNext;
        }

        return pBehind;
	}

    // ====================���Դ���====================
// ����Ҫ�ҵĽ���������м�
    void Test1()
    {
        printf("=====Test1 starts:=====\n");
        ListNode* pNode1 = CreateListNode(1);
        ListNode* pNode2 = CreateListNode(2);
        ListNode* pNode3 = CreateListNode(3);
        ListNode* pNode4 = CreateListNode(4);
        ListNode* pNode5 = CreateListNode(5);

        ConnectListNodes(pNode1, pNode2);
        ConnectListNodes(pNode2, pNode3);
        ConnectListNodes(pNode3, pNode4);
        ConnectListNodes(pNode4, pNode5);

        printf("expected result: 4.\n");
        ListNode* pNode = FindKthToTail(pNode1, 2);
        PrintListNode(pNode);

        DestroyList(pNode1);
    }

    // ����Ҫ�ҵĽ���������β���
    void Test2()
    {
        printf("=====Test2 starts:=====\n");
        ListNode* pNode1 = CreateListNode(1);
        ListNode* pNode2 = CreateListNode(2);
        ListNode* pNode3 = CreateListNode(3);
        ListNode* pNode4 = CreateListNode(4);
        ListNode* pNode5 = CreateListNode(5);

        ConnectListNodes(pNode1, pNode2);
        ConnectListNodes(pNode2, pNode3);
        ConnectListNodes(pNode3, pNode4);
        ConnectListNodes(pNode4, pNode5);

        printf("expected result: 5.\n");
        ListNode* pNode = FindKthToTail(pNode1, 1);
        PrintListNode(pNode);

        DestroyList(pNode1);
    }

    // ����Ҫ�ҵĽ���������ͷ���
    void Test3()
    {
        printf("=====Test3 starts:=====\n");
        ListNode* pNode1 = CreateListNode(1);
        ListNode* pNode2 = CreateListNode(2);
        ListNode* pNode3 = CreateListNode(3);
        ListNode* pNode4 = CreateListNode(4);
        ListNode* pNode5 = CreateListNode(5);

        ConnectListNodes(pNode1, pNode2);
        ConnectListNodes(pNode2, pNode3);
        ConnectListNodes(pNode3, pNode4);
        ConnectListNodes(pNode4, pNode5);

        printf("expected result: 1.\n");
        ListNode* pNode = FindKthToTail(pNode1, 5);
        PrintListNode(pNode);

        DestroyList(pNode1);
    }

    // ���Կ�����
    void Test4()
    {
        printf("=====Test4 starts:=====\n");
        printf("expected result: nullptr.\n");
        ListNode* pNode = FindKthToTail(nullptr, 100);
        PrintListNode(pNode);
    }

    // ��������ĵڶ���������������Ľ������
    void Test5()
    {
        printf("=====Test5 starts:=====\n");
        ListNode* pNode1 = CreateListNode(1);
        ListNode* pNode2 = CreateListNode(2);
        ListNode* pNode3 = CreateListNode(3);
        ListNode* pNode4 = CreateListNode(4);
        ListNode* pNode5 = CreateListNode(5);

        ConnectListNodes(pNode1, pNode2);
        ConnectListNodes(pNode2, pNode3);
        ConnectListNodes(pNode3, pNode4);
        ConnectListNodes(pNode4, pNode5);

        printf("expected result: nullptr.\n");
        ListNode* pNode = FindKthToTail(pNode1, 6);
        PrintListNode(pNode);

        DestroyList(pNode1);
    }

    // ��������ĵڶ�������Ϊ0
    void Test6()
    {
        printf("=====Test6 starts:=====\n");
        ListNode* pNode1 = CreateListNode(1);
        ListNode* pNode2 = CreateListNode(2);
        ListNode* pNode3 = CreateListNode(3);
        ListNode* pNode4 = CreateListNode(4);
        ListNode* pNode5 = CreateListNode(5);

        ConnectListNodes(pNode1, pNode2);
        ConnectListNodes(pNode2, pNode3);
        ConnectListNodes(pNode3, pNode4);
        ConnectListNodes(pNode4, pNode5);

        printf("expected result: nullptr.\n");
        ListNode* pNode = FindKthToTail(pNode1, 0);
        PrintListNode(pNode);

        DestroyList(pNode1);
    }
    public:
    int main()
    {
        Test1();
        Test2();
        Test3();
        Test4();
        Test5();
        Test6();

        return 0;
    }
};

