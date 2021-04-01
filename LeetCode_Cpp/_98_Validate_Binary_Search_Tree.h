/*

Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:


Input: root = [2,1,3]
Output: true
Example 2:


Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/validate-binary-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#pragma once
#include "Global.h"
#include <stack>

class _98_Validate_Binary_Search_Tree
{
public:
	void Test() {
		// string head = "226";
		// _98_Validate_Binary_Search_Tree::numDecodings(head);
	}

    /* 限定以 root 为根的子树节点必须满足 max.val > root.val > min.val */
    // bool isValidBST(TreeNode* root, TreeNode* min, TreeNode* max) {
	// 	if(root == nullptr) return true;
	// 	if(min != nullptr && root->val <= min->val) return false;
	// 	if(max != nullptr && root->val >= max->val) return false;
    //     // 限定左子树的最大值是 root.val，右子树的最小值是 root.val
	// 	return isValidBST(root->left,min,root) && isValidBST(root->right,root,max);
    // }

    bool isValidBST(TreeNode* root, TreeNode* min, TreeNode* max) {
		if(root == nullptr) return true;
		if(min != nullptr && root->val <= min->val) return false;
		if(max != nullptr && root->val >= max->val) return false;

		return true;
    }

	bool isValidBST(TreeNode* root) {
		// 1. 递归：时间 65% 内存84% 
		// return isValidBST(root,nullptr,nullptr);
		// 2. 栈：中序遍历：时间14% 内存90% 
		// 「中序遍历」得到的值构成的序列一定是升序的，
		// 这启示我们在中序遍历的时候实时检查当前节点的值是否大于前一个中序遍历到的节点的值即可。
		stack<TreeNode*> stack;
		long long inorder = (long long)INT_MIN - 1;

		while (!stack.empty() || root != nullptr)
		{
			while (root != nullptr)
			{
				stack.push(root);
				root = root->left;
			}
			
			root = stack.top();
			stack.pop();

			// 如果中序遍历得到的节点的值小于等于前一个 inorder ，说明不是二叉搜索树
			if(root->val <= inorder)
				return false;
			
			inorder = root->val;
			root = root->right;
		}
		return true;
	}
};