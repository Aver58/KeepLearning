// 只编译1次
#pragma once

#include <vector>

struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pright;
    BinaryTreeNode(int value){m_nValue = value;}
};

__declspec( dllexport ) BinaryTreeNode* CreateTreeNode(int value);
// __declspec( dllexport ) void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pChild);
__declspec( dllexport ) void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pChild,BinaryTreeNode* pChild1);
__declspec( dllexport ) void PrintTreeNode(BinaryTreeNode* pNode);
__declspec( dllexport ) void PrintTree(BinaryTreeNode* pRoot);
__declspec( dllexport ) void DestroyTree(BinaryTreeNode* pRoot);