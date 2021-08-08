// ������36��������������˫������
// ��Ŀ������һ�ö��������������ö���������ת����һ�������˫������
// Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��

#pragma once
#include "Utilities\BinaryTree.h"

class _36_ConvertBinarySearchTree
{
    // ������������մ�С�����˳������������������
    BinaryTreeNode* Convert(BinaryTreeNode* pRootOfTree)
    {
        BinaryTreeNode* pLastNodeInList = nullptr;
        ConvertNode(pRootOfTree, &pLastNodeInList);

        // pLastNodeInListָ��˫�������β�ڵ�
        // ������Ҫ����ͷ���
        BinaryTreeNode* pHeadNodeInList = pLastNodeInList;
        while (pHeadNodeInList != nullptr && pHeadNodeInList->m_pLeft != nullptr)
            pHeadNodeInList = pHeadNodeInList->m_pLeft;
    
        return pHeadNodeInList;
    }

    void ConvertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInList)
    {
        if (pNode == nullptr)
            return;
    
        BinaryTreeNode* pCurrent = pNode;

        if (pCurrent->m_pLeft != nullptr)
            ConvertNode(pCurrent->m_pLeft, pLastNodeInList);

        // �������λ�ã�
        // ���û������todo ���Լ�����һ��
        pCurrent->m_pLeft = *pLastNodeInList;
        if (*pLastNodeInList != nullptr)
            (*pLastNodeInList)->m_pRight = pCurrent;
    
        *pLastNodeInList = pCurrent;

        if (pCurrent->m_pRight != nullptr)
            ConvertNode(pCurrent->m_pRight, pLastNodeInList);
    }
}

