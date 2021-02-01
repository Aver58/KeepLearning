/*
Invert a binary tree.

Example:

Input:

	 4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

	 4
   /   \
  7     2
 / \   / \
9   6 3   1
Trivia:
This problem was inspired by this original tweet by Max Howell:

Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so f*** off.
*/
#pragma once
#include "Global.h"

class _226_Invert_Binary_Tree
{
public:
    int count = 0;
	void Test() {
        TreeNode* head = new TreeNode(3);
        TreeNode* head1 = new TreeNode(1);
        TreeNode* head2 = new TreeNode(4);
        //TreeNode* head3 = new TreeNode(3);
        TreeNode* head4 = new TreeNode(2);
        head->left = head1;
        head->right = head2;
        //head1->left = head3;
        head1->right = head4;
        invertTree(head);
	}

    // 前序
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return nullptr;
        /**** 前序遍历位置 ****/
        TreeNode* temp = root->left;
           // 交换它的左右子节点
        root->left = root->right;
        root->right = temp;
        // 让左右子节点继续翻转它们的子节点
        invertTree(root->left);
        /**** 中序遍历位置 ****/    
        invertTree(root->left);
        /**** 后序遍历位置 ****/

        return root;
    }

    // 中序遍历
    //TreeNode* invertTree(TreeNode* root) {
    //    if (root == nullptr)
    //        return nullptr;
    //    /**** 前序遍历位置 ****/

    //    // 让左右子节点继续翻转它们的子节点
    //    TreeNode* temp = invertTree(root->left);
    //    /**** 中序遍历位置 ****/

    //    // 交换它的左右子节点
    //    root->left = root->right;
    //    root->right = temp;

    //    invertTree(root->left);
    //    /**** 后序遍历位置 ****/

    //    return root;
    //}

    // 后序
    //TreeNode* invertTree(TreeNode* root) {
    //    if (root == nullptr)
    //        return nullptr;
    //    /**** 前序遍历位置 ****/
    //    // 让左右子节点继续翻转它们的子节点
    //    invertTree(root->left);
    //    /**** 中序遍历位置 ****/
    //    invertTree(root->left);
    //    /**** 后序遍历位置 ****/
    //    // 交换它的左右子节点
    //    TreeNode* temp = root->left;
    //    root->left = root->right;
    //    root->right = temp;

    //    return root;
    //}
};