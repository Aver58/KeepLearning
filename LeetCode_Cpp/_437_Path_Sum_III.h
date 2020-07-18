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

	static int pathSum(TreeNode* root, int sum, int curSum)
	{
		if (root == nullptr)
		{
			return 0;
		}
		int count = 0;
		curSum += root->val;
		if (sum == curSum)
		{
			count += 1;
		}
		if (root->left != nullptr)
		{
			count += pathSum(root->left, sum, curSum);
		}
		if (root->right != nullptr)
		{
			count += pathSum(root->right, sum, curSum);
		}
		return count;
	}

	static int pathSum(TreeNode* root, int sum) {
		// 1. 层序遍历(借助队列)  递归所有情况 40ms 57%
		//回溯pathSum(TreeNode* root, int sum,int curSum)
		if (root == nullptr) {
			return 0;
		}
		queue<TreeNode*> qt;
		qt.push(root);
		int res = 0;
		while (!qt.empty())
		{
			TreeNode *node = qt.front();
			res += pathSum(node, sum, 0);
			qt.pop();

			if (node->left != nullptr)
			{
				qt.push(node->left);
			}
			if (node->right != nullptr)
			{
				qt.push(node->right);
			}
		}
		return res;
	}

	//2. 用map记录结果，每个结点都遍历一遍map 看不懂
	//static unordered_map<int, int> m;

	//static int get(int v) {
	//	unordered_map<int, int>::iterator it = m.find(v);
	//	if (it == m.end())return 0;
	//	else return it->second;
	//}

	//static void pathSumHelper(TreeNode* root, int target, int* ret, int sum) {
	//	int nowSum = sum + root->val;

	//	int count = get(nowSum - target);
	//	*ret += count;

	//	if (!root->left && !root->right) {

	//	}
	//	else {
	//		int t = get(nowSum);
	//		m[nowSum] = t + 1;

	//		if (root->left) {
	//			pathSumHelper(root->left, target, ret, nowSum);
	//		}
	//		m[nowSum] = t + 1;
	//		if (root->right) {
	//			pathSumHelper(root->right, target, ret, nowSum);
	//		}

	//		m[nowSum] = t;
	//	}
	//}

	//static int pathSum(TreeNode* root, int sum) {
	//	if (root == NULL)return 0;
	//	m.clear();
	//	m[0] = 1;
	//	int ret = 0;
	//	pathSumHelper(root, sum, &ret, 0);
	//	return ret;
	//}
};

