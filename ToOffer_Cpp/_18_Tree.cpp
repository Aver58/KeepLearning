#include "_18_Tree.h"

bool DoesTree1HaveTree2(BinaryTreeNode* pRoot1,BinaryTreeNode* pRoot2)
{
    if(pRoot2 == NULL)
        return true;
    if(pRoot1 == NULL)
        return false;
    if(pRoot1->m_value != pRoot2->m_value)
        return false;
    return DoesTree1HaveTree2(pRoot1->m_Left,pRoot2->m_Left) 
        && DoesTree1HaveTree2(pRoot1->m_Right,pRoot2->m_Right);
}

bool BinaryTree::HasSubtree(BinaryTreeNode* pRoot1,BinaryTreeNode* pRoot2)
{
    if(pRoot1 == NULL && pRoot2 == NULL)
        return false;
    
    bool result = false;
    if(pRoot1->m_value == pRoot2->m_value)
    {
        result = DoesTree1HaveTree2(pRoot1,pRoot2);
    }

    if(!result)
        result = HasSubtree(pRoot1->m_Left,pRoot2);

    if(!result)
        result = HasSubtree(pRoot1->m_Right,pRoot2);

    return result;
}