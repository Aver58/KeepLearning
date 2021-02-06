#pragma once
/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

	3
   / \
  9  20
	/  \
   15   7
*/

#include "Global.h"

class _105_Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal
{ 
private:
	unordered_map<int, int> indexMap;
public:
	void Test() {
		vector<int> preorder{ 3,9,20,15,7 };
		vector<int> inorder{ 9,3,15,20,7 };
		TreeNode* root = buildTree(preorder, inorder);
	/*	while (root != nullptr)
		{
			cout << root->val << ",";
		}*/
	}

	// 条件： 输入列表无重复
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int n = preorder.size();
		// 构造哈希映射，帮助我们快速定位根节点
		// 注意，这里的<n，错误写成n-1就会报错
		for (int i = 0; i < n; ++i) {
			indexMap[inorder[i]] = i;
		}
		return buildTree(preorder, inorder, 0, n - 1, 0, n - 1);
	}

	TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
		if (preorder_left > preorder_right) {
			return nullptr;
		}

		// 前序遍历中的第一个节点就是根节点
		int preorder_root = preorder_left;
		// 在中序遍历中定位根节点
		int inorder_root = indexMap[preorder[preorder_root]];

		// 先把根节点建立出来
		TreeNode* root = new TreeNode(preorder[preorder_root]);
		// 得到左子树中的节点数目
		int size_left_subtree = inorder_root - inorder_left;
		// 递归地构造左子树，并连接到根节点
		// 先序遍历中「从 左边界+1 开始的 size_left_subtree」个元素就对应了中序遍历中「从 左边界 开始到 根节点定位-1」的元素
		root->left = buildTree(preorder, inorder, preorder_left + 1, preorder_left + size_left_subtree, inorder_left, inorder_root - 1);
		// 递归地构造右子树，并连接到根节点
		// 先序遍历中「从 左边界+1+左子树节点数目 开始到 右边界」的元素就对应了中序遍历中「从 根节点定位+1 到 右边界」的元素
		root->right = buildTree(preorder, inorder, preorder_left + size_left_subtree + 1, preorder_right, inorder_root + 1, inorder_right);
		return root;
	}

};