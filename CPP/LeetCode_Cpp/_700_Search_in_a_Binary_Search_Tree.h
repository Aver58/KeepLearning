/*
You are given the root of a binary search tree (BST) and an integer val.

Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

 

Example 1:


Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]
Example 2:


Input: root = [4,2,7,1,3], val = 5
Output: []
 

Constraints:

The number of nodes in the tree is in the range [1, 5000].
1 <= Node.val <= 107
root is a binary search tree.
1 <= val <= 107

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-in-a-binary-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#pragma once
#include "Global.h"

class _700_Search_in_a_Binary_Search_Tree
{ 
public:
	void Test() {

	}

    TreeNode* searchBST(TreeNode* root, int val) {
        // 1. 递归。
        if(root == nullptr) return nullptr;
        if(root->val == val) return root;
        if (val < root->val) return searchBST(root->left,val);
        if (val > root->val) return searchBST(root->right,val);
        
        // return nullptr;
        // 2. 迭代
        while (root)
        {
            if (val < root->val)
            {
                root = root->left;
            }
            else if(val > root->val)
            {
                root = root->right;
            }
            else
            {
                return root;
            }
        }
        return root;
    }
};