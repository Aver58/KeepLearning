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