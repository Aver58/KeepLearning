// 面试题36：二叉搜索树与双向链表
// 题目：输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
// 要求不能创建任何新的结点，只能调整树中结点指针的指向。

#pragma once
#include "Utilities\BinaryTree.h"

class _36_ConvertBinarySearchTree
{
    // 中序遍历，按照从小到大的顺序遍历二叉树，左根右
    BinaryTreeNode* Convert(BinaryTreeNode* pRootOfTree)
    {
        BinaryTreeNode* pLastNodeInList = nullptr;
        ConvertNode(pRootOfTree, &pLastNodeInList);

        // pLastNodeInList指向双向链表的尾节点
        // 我们需要的是头结点
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

        // 中序遍历位置，
        // 这个没看懂，todo 再自己分析一遍
        pCurrent->m_pLeft = *pLastNodeInList;
        if (*pLastNodeInList != nullptr)
            (*pLastNodeInList)->m_pRight = pCurrent;
    
        *pLastNodeInList = pCurrent;

        if (pCurrent->m_pRight != nullptr)
            ConvertNode(pCurrent->m_pRight, pLastNodeInList);
    }
}

