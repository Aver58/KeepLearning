// 面试题34：二叉树中和为某一值的路径
// 题目：输入一棵二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所
// 有路径。从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。

#pragma once
#include "Utilities\BinaryTree.h"
#include <vector>
class _34_PathInTree
{
	// 栈
	void FindPath(BinaryTreeNode* pRoot, int expectedSum)
	{
		if (pRoot == nullptr)
			return;

		std::vector<int> path;
		int currentSum = 0;
		FindPath(pRoot, expectedSum, path, currentSum);
	}

	// 回溯
	void FindPath(BinaryTreeNode* pRoot, int expectedSum, std::vector<int>& path, int& currentSum)
	{
		if (pRoot == nullptr)
			return;

		currentSum += pRoot->m_nValue;
		path.push_back(pRoot->m_nValue);

		bool isLeaf = pRoot->m_pLeft == nullptr && pRoot->m_pRight == nullptr;
		if (isLeaf && expectedSum == currentSum)
		{
			// 如果是叶子节点的话，打印出来
			printf("A path is found: ");
			//C++ stack 的栈是不能遍历的，所以使用vector
			std::vector<int>::iterator iter = path.begin();
			for (; iter != path.end(); ++iter)
				printf("%d\t", *iter);

			printf("\n");
		}

		// 如果不是叶结点，则遍历它的子结点
		if (pRoot->m_pLeft)
			FindPath(pRoot->m_pLeft, expectedSum, path, currentSum);
		if (pRoot->m_pRight)
			FindPath(pRoot->m_pRight, expectedSum, path, currentSum);

		// 在返回到父结点之前，在路径上删除当前结点，
		// 并在currentSum中减去当前结点的值
		path.pop_back();
		currentSum -= pRoot->m_nValue;
	}
};