// ������35����������ĸ���
// ��Ŀ����ʵ�ֺ���ComplexListNode* Clone(ComplexListNode* pHead)����
// ��һ�����������ڸ��������У�ÿ����������һ��m_pNextָ��ָ����һ��
// ����⣬����һ��m_pSibling ָ�������е����������nullptr��

#pragma once

struct ComplexListNode
{
    int m_nValue;
    ComplexListNode* m_pNext;
    ComplexListNode* m_pSibling;
};

class _35_CopyComplexList
{
    // 1. ��������m_pNext������m_pSibling��ϵ n*n
    // 2. �ռ任ʱ�� n
    // 3. ��ԭ�пռ䣬������������ڵ�һ�ݣ����ӹ�ϵ
    // �� ����ԭ�����нڵ�һ�ݣ����ӳ�һ��2�����ȵ�����
    // �� ����sibling
    // �� ���2��

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
            // ָ��m_pSibling����һ���ڵ�
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

