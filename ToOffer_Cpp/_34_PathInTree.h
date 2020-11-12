// ������34���������к�Ϊĳһֵ��·��
// ��Ŀ������һ�ö�������һ����������ӡ���������н��ֵ�ĺ�Ϊ������������
// ��·���������ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����

#pragma once
#include "Utilities\BinaryTree.h"
#include <vector>
class _34_PathInTree
{
	// ջ
	void FindPath(BinaryTreeNode* pRoot, int expectedSum)
	{
		if (pRoot == nullptr)
			return;

		std::vector<int> path;
		int currentSum = 0;
		FindPath(pRoot, expectedSum, path, currentSum);
	}

	// ����
	void FindPath(BinaryTreeNode* pRoot, int expectedSum, std::vector<int>& path, int& currentSum)
	{
		if (pRoot == nullptr)
			return;

		currentSum += pRoot->m_nValue;
		path.push_back(pRoot->m_nValue);

		bool isLeaf = pRoot->m_pLeft == nullptr && pRoot->m_pRight == nullptr;
		if (isLeaf && expectedSum == currentSum)
		{
			// �����Ҷ�ӽڵ�Ļ�����ӡ����
			printf("A path is found: ");
			//C++ stack ��ջ�ǲ��ܱ����ģ�����ʹ��vector
			std::vector<int>::iterator iter = path.begin();
			for (; iter != path.end(); ++iter)
				printf("%d\t", *iter);

			printf("\n");
		}

		// �������Ҷ��㣬����������ӽ��
		if (pRoot->m_pLeft)
			FindPath(pRoot->m_pLeft, expectedSum, path, currentSum);
		if (pRoot->m_pRight)
			FindPath(pRoot->m_pRight, expectedSum, path, currentSum);

		// �ڷ��ص������֮ǰ����·����ɾ����ǰ��㣬
		// ����currentSum�м�ȥ��ǰ����ֵ
		path.pop_back();
		currentSum -= pRoot->m_nValue;
	}
};