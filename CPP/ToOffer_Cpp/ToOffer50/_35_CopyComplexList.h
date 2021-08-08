// 面试题35：复杂链表的复制
// 题目：请实现函数ComplexListNode* Clone(ComplexListNode* pHead)，复
// 制一个复杂链表。在复杂链表中，每个结点除了有一个m_pNext指针指向下一个
// 结点外，还有一个m_pSibling 指向链表中的任意结点或者nullptr。

#pragma once

struct ComplexListNode
{
    int m_nValue;
    ComplexListNode* m_pNext;
    ComplexListNode* m_pSibling;
};

class _35_CopyComplexList
{
    // 1. 复制链表m_pNext、复制m_pSibling关系 n*n
    // 2. 空间换时间 n
    // 3. 在原有空间，复制所有链表节点一份，连接关系
    // ① 复制原来所有节点一份，连接成一个2倍长度的链表
    // ② 连接sibling
    // ③ 拆成2份

    ComplexListNode* CloneNodes(ComplexListNode* pHead)()
    {
        ComplexListNode* pNode = pHead;
        while (pNode != nullptr)
        {
            ComplexListNode* pCloned = new ComplexListNode();
            pCloned->m_nValue = pNode->m_nValue;
            pCloned->m_pNext = pNode->m_pNext;
            pCloned->m_pSibling = nullptr;

            pNode->m_pNext = pCloned;

            pNode = pCloned->m_pNext;
        }
    }

    ComplexListNode* ConnectSiblingNodes(ComplexListNode* pHead)()
    {
        ComplexListNode* pNode = pHead;
        while (pNode != nullptr)
        {
            ComplexListNode* pCloned = pNode->m_pNext;
            // 指向m_pSibling的下一个节点
            if (pNode->m_pSibling != nullptr)
                pCloned->m_pSibling = pNode->m_pSibling->m_pNext;

            pNode = pCloned->m_pNext;
        }
    }

    ComplexListNode* ReconnectNodes(ComplexListNode* pHead)()
    {
        ComplexListNode* pNode = pHead;
        ComplexListNode* pCloneHead = nullptr;
        ComplexListNode* pCloneNode = nullptr;

        if (pNode != nullptr)
        {
            pCloneHead = pNode->m_pNext;
            pCloneNode = pCloneHead;
            pNode = pCloneNode->m_pNext;
        }

        while (pNode != nullptr)
        {
            if (pNode != nullptr)
                pCloneNode->m_pNext = pNode->m_pNext;
            pCloneNode = pCloneNode->m_pNext;
            pNode->m_pNext = pCloneNode->m_pNext;
            pNode = pNode->m_pNext;
        }

        return pCloneHead;
    }

    ComplexListNode* Clone(ComplexListNode* pHead)()
    {
        CloneNodes(pHead);
        ConnectSiblingNodes(pHead);
        return ReconnectNodes(pHead);
    }
}

