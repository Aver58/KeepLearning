#include <iostream>
using namespace std;

struct BinaryTreeNode
{
    int m_value;
    BinaryTreeNode *m_Left;
    BinaryTreeNode *m_Right;

    BinaryTreeNode(int n)
    {
        m_value = n;
        m_Left = NULL;
        m_Right = NULL;
    }
};

class BinaryTree
{
    public:
        BinaryTree(){};
        bool HasSubtree(BinaryTreeNode*,BinaryTreeNode*);
};