#pragma once
/*
Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list 
and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
1. 左节点空，右节点是链表
2. 前序遍历顺序
Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [0]
Output: [0]
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include "Global.h"

class _114_Flatten_Binary_Tree_to_Linked_List
{ 
private:
	TreeNode* last = nullptr;

public:
	void Test() {

	}

	// 神仙思路：先遍历右边，然后保存右节点
	void flatten(TreeNode* root) 
	{
		if (root == nullptr) return;

		flatten(root->right);
		flatten(root->left);
		/**** 后序遍历位置 ****/
		root->right = last;
		root->left = nullptr;

		last = root;
	}

	void flatten(TreeNode* root)
	{
		if (root == nullptr) return;

		flatten(root->left);
		flatten(root->right);
		/**** 后序遍历位置 ****/
		//在还没操作节点右子树前，不能破坏该节点的右子树指向。所以采用后序遍历。
		TreeNode* right = root->right;

		root->right = root->left;
		root->left = nullptr;

		TreeNode* p = root;
		while (p->right != nullptr)
		{
			p = p->right;
		}

		p->right = right;
	}
};