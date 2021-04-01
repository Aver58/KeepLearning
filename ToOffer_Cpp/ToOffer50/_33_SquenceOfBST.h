// 面试题33：二叉搜索树的后序遍历序列
// 题目：输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
// 如果是则返回true，否则返回false。假设输入的数组的任意两个数字都互不相同。

#pragma once
class _33_SquenceOfBST
{
	// 二叉搜索树: 左子树的值始终小于根节点
	// BST：Binary Search Tree，二叉搜索树
	bool VerifySquenceOfBST(int sequence[], int length)
	{
		if (sequence == nullptr || length <= 0)
			return false;
		
		// 根节点的值是后序遍历的最后一个
		int rootVal = sequence[length - 1];

		// 左子树所有节点值小于根节点值
		int leftLen = 0;
		for (leftLen = 0; leftLen < length - 1; leftLen++)
		{
			if (sequence[leftLen] > rootVal)
				break;
		}

		// 右子树所有节点值大于根节点值
		int rightLen = leftLen;
		for (; rightLen < length - 1; rightLen++)
		{
			if (sequence[rightLen] < rootVal)
				return false;
		}

		// 递归左子树
		bool left;
		if (leftLen > 0)
			left = VerifySquenceOfBST(sequence, leftLen);
		// 递归右子树
		bool right;
		if (rightLen < length - 1)
			right = VerifySquenceOfBST(sequence + rightLen, length - 1 - leftLen);

		return left && right;
	}
};

