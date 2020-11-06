#pragma once
#include "Utilities\BinaryTree.h"
#include <queue>

class _32_PrintTree
{
    // 面试题32（一）：不分行从上往下打印二叉树
    // 题目：从上往下打印出二叉树的每个结点，同一层的结点按照从左到右的顺序打印。
    void PrintTreeFromTopToBottom(BinaryTreeNode* pRoot)
    {
        if (pRoot == nullptr)
            return;
        std::queue<BinaryTreeNode*> nodes;
        nodes.push(pRoot);
        while (!nodes.empty())
        {
            BinaryTreeNode* pNode = nodes.front();
            printf("%d ", pNode->m_nValue);
            nodes.pop();

            if (pNode->m_pLeft)
                nodes.push(pNode->m_pLeft);

            if (pNode->m_pRight)
                nodes.push(pNode->m_pRight);
        }
    }

    // 面试题32（二）：分行从上到下打印二叉树
    // 题目：从上到下按层打印二叉树，同一层的结点按从左到右的顺序打印，每一层
    // 打印到一行。
	// 借助队列，递归
	void PrintTreesInLines(BinaryTreeNode* pRoot)
	{
		if (pRoot == nullptr)
			return;
		std::queue<BinaryTreeNode*> nodes;
		nodes.push(pRoot);
		int nextLevelCount = 0;  // 下一层节点数
		int toBePrinted = 1;// 当前层还没有打印层数

		while (!nodes.empty())
		{
			BinaryTreeNode* pNode = nodes.front();
			printf("%d ", pNode->m_nValue);

			if (pNode->m_pLeft != nullptr)
			{
				nodes.push(pNode->m_pLeft);
				++nextLevelCount;
			}
			if (pNode->m_pRight != nullptr)
			{
				nodes.push(pNode->m_pRight);
				++nextLevelCount;
			}

			nodes.pop();
			--toBePrinted;
			if (toBePrinted == 0)
			{
				printf("\n");
				toBePrinted = nextLevelCount;
				nextLevelCount = 0;
			}
		}
	}

    // 面试题32（三）：之字形打印二叉树
    // 题目：请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺
    // 序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，
    // 其他行以此类推。
    void PrintTreesInZigzag(BinaryTreeNode* pRoot)
    {
        if (pRoot == nullptr)
            return;
        // 定义2个栈，弹出栈，打印一个节点，保存它的子节点到另一个栈，当一层所有子节点打印完毕，交换2个栈继续打印下一层
        std:stack<BinaryTreeNode*> level[2];
        int current = 0;
        int next = 1;
        level[current].push(pRoot);
        while (!level[current].empty() || !level[next].empty())
        {
            BinaryTreeNode* pNode = level[current].top();
            level[current].pop();
            printf("%d ", pNode->m_nValue);

            if (current == 0)
            {
                if (pNode->m_pLeft)
                    level[next].push(pNode->m_pLeft);
                if (pNode->m_pRight)
                    level[next].push(pNode->m_pRight);
            }
            else
            {
                if (pNode->m_pRight)
                    level[next].push(pNode->m_pRight);
                if (pNode->m_pLeft)
                    level[next].push(pNode->m_pLeft);
            }

            if (level[current].empty())
            {
                printf("\n");
                current = 1 - next;
                next = 1 - current;
            }
        }
    }
    
    void Print(BinaryTreeNode* pRoot)
    {
        // 测试
        PrintTreesInZigzag(pRoot);
    }

    // ====================测试代码====================
    //            8
    //        6      10
    //       5 7    9  11
    void Test1()
    {
        BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
        BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
        BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
        BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
        BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
        BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
        BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);

        ConnectTreeNodes(pNode8, pNode6, pNode10);
        ConnectTreeNodes(pNode6, pNode5, pNode7);
        ConnectTreeNodes(pNode10, pNode9, pNode11);

        printf("====Test1 Begins: ====\n");
        printf("Expected Result is:\n");
        printf("8 \n");
        printf("6 10 \n");
        printf("5 7 9 11 \n\n");

        printf("Actual Result is: \n");
        Print(pNode8);
        printf("\n");

        DestroyTree(pNode8);
    }

    //            5
    //          4
    //        3
    //      2
    void Test2()
    {
        BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
        BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
        BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
        BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);

        ConnectTreeNodes(pNode5, pNode4, nullptr);
        ConnectTreeNodes(pNode4, pNode3, nullptr);
        ConnectTreeNodes(pNode3, pNode2, nullptr);

        printf("====Test2 Begins: ====\n");
        printf("Expected Result is:\n");
        printf("5 \n");
        printf("4 \n");
        printf("3 \n");
        printf("2 \n\n");

        printf("Actual Result is: \n");
        Print(pNode5);
        printf("\n");

        DestroyTree(pNode5);
    }

    //        5
    //         4
    //          3
    //           2
    void Test3()
    {
        BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
        BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
        BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
        BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);

        ConnectTreeNodes(pNode5, nullptr, pNode4);
        ConnectTreeNodes(pNode4, nullptr, pNode3);
        ConnectTreeNodes(pNode3, nullptr, pNode2);

        printf("====Test3 Begins: ====\n");
        printf("Expected Result is:\n");
        printf("5 \n");
        printf("4 \n");
        printf("3 \n");
        printf("2 \n\n");

        printf("Actual Result is: \n");
        Print(pNode5);
        printf("\n");

        DestroyTree(pNode5);
    }

    void Test4()
    {
        BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

        printf("====Test4 Begins: ====\n");
        printf("Expected Result is:\n");
        printf("5 \n\n");

        printf("Actual Result is: \n");
        Print(pNode5);
        printf("\n");

        DestroyTree(pNode5);
    }

    void Test5()
    {
        printf("====Test5 Begins: ====\n");
        printf("Expected Result is:\n");

        printf("Actual Result is: \n");
        Print(nullptr);
        printf("\n");
    }

    //        100
    //        /
    //       50   
    //         \
    //         150
    void Test6()
    {
        BinaryTreeNode* pNode100 = CreateBinaryTreeNode(100);
        BinaryTreeNode* pNode50 = CreateBinaryTreeNode(50);
        BinaryTreeNode* pNode150 = CreateBinaryTreeNode(150);

        ConnectTreeNodes(pNode100, pNode50, nullptr);
        ConnectTreeNodes(pNode50, nullptr, pNode150);

        printf("====Test6 Begins: ====\n");
        printf("Expected Result is:\n");
        printf("100 \n");
        printf("50 \n");
        printf("150 \n\n");

        printf("Actual Result is: \n");
        Print(pNode100);
        printf("\n");
    }
    public:
    int main()
    {
        Test1();
        Test2();
        Test3();
        //Test4();
        //Test5();
        //Test6();

        return 0;
    }

};