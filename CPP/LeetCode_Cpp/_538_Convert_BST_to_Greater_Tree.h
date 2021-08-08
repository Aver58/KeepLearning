#pragma once
/*
Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

Example 1:
Input:

"bbbab"
Output:
4
One possible longest palindromic subsequence is "bbbb".
Example 2:
Input:

"cbbd"
Output:
2
One possible longest palindromic subsequence is "bb".
*/

#include "Global.h"

class _538_Convert_BST_to_Greater_Tree
{
private:
	int sum = 0;
public:
	void Test() {
	}

    // 反序中序遍历:sum记录已累加的值
    TreeNode* convertBST(TreeNode* root) {
		if (root != nullptr)
		{
			convertBST(root->right);
			// 中序遍历位置
			sum += root->val;
			root->val = sum;

			convertBST(root->left);
		}
		return root;
	}
};