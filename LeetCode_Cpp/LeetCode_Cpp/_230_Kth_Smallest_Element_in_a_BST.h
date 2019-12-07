#pragma once
/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Example 1:

Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1
Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
	   5
	  / \
	 3   6
	/ \
   2   4
  /
 1
Output: 3
Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? 
How would you optimize the kthSmallest routine?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include "Global.h"

class _230_Kth_Smallest_Element_in_a_BST
{
public:
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
	/*	head3->left = new TreeNode(3);
		head3->right = new TreeNode(-2);
		head4->right = new TreeNode(1);
		head2->right = new TreeNode(11);*/
		kthSmallest(head,1);
	}

	void BackTrack(TreeNode* root, int k, int& result, int& i) {
		if (root != nullptr) {
			BackTrack(root->left, k, result, i);
			i++;
			if (k == i) {
				result = root->val;
				return;
			}
			BackTrack(root->right, k, result, i);
		}
	}

	int kthSmallest(TreeNode* root, int k) {
		//1. 迭代版本 32 ms 37.96%
		//按中序排列，就是升序排列，就能拿到第K小的元素
		//if (root == NULL || k<=0)
		//	return -1;

		//stack<TreeNode*> s;
		//TreeNode* current = root;
		//while (current != nullptr || !s.empty())
		//{
		//	// 左根右，先把所有左根进栈
		//	while (current)
		//	{
		//		s.push(current);
		//		current = current->left;
		//	}

		//	if (!s.empty())
		//	{
		//		// 不为空的话，出栈，拿到的是根
		//		current = s.top();
		//		s.pop();
		//		if (k == 1)
		//			return current->val;
		//		k--;
		//		current = current->right;
		//	}
		//}
		//return -1;

		//2. 递归版本 24ms 78%
		int result, i = 0;
		BackTrack(root, k, result, i);
		return result;
	}
};

