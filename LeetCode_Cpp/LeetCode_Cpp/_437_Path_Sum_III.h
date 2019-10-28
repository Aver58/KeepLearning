#pragma once
/*
You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

	  10
	 /  \
	5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-sum-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include "Global.h"

class _437_Path_Sum_III
{
public:
	static void Test() {
		TreeNode* head = new TreeNode(10);
		TreeNode* head1 = new TreeNode(5);
		TreeNode* head2 = new TreeNode(-3);
		TreeNode* head3 = new TreeNode(3);
		TreeNode* head4 = new TreeNode(2);
		head->left = head1;
		head->right = head2;
		head1->left = head3;
		head1->right = head4;
		head3->left = new TreeNode(3);
		head3->right = new TreeNode(-2);
		head4->right = new TreeNode(1);
		head2->right = new TreeNode(11);

		std::cout << _437_Path_Sum_III::pathSum(head,8);
	}

	static int pathSum(TreeNode* root, int sum) {
		// 1. 层序遍历(借助栈)
		// 2. 回溯pathSum(TreeNode* root, int sum,int curSum)
		int count = 0;
		if (root == NULL)
		{
			return 0;
		}
	}
};

