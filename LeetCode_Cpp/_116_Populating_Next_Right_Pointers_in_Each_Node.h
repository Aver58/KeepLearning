#pragma once
/*
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. 
The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Follow up:

You may only use constant extra space.
Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.

Example 1:

Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.

Constraints:

The number of nodes in the given tree is less than 4096.
-1000 <= node.val <= 1000
*/

#include "Global.h"

// Definition for a Node.
class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	//Node() : val(0), left(NULL), right(NULL), next(NULL) {}
	Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
	//Node(int _val, Node* _left, Node* _right, Node* _next) : val(_val), left(_left), right(_right), next(_next) {}
};

class _116_Populating_Next_Right_Pointers_in_Each_Node
{ 
public:
	void Test() {
		Node* head = new Node(-1);
		Node* head1 = new Node(5);
		Node* head2 = new Node(3);
		Node* head3 = new Node(4);
		Node* head4 = new Node(0);
		head->next = head1;
		head1->next = head2;
		head2->next = head3;
		head3->next = head4;
		Node* res = connect(head);
		while (res)
		{
			cout << res->val;
			res = res->next;
		}
	}

	Node* connect(Node* root) {
		if (root == NULL)
			return NULL;
		connectTwoNode(root->left, root->right);
	}

	Node* connectTwoNode(Node* left, Node* right) {
		if (left == NULL || right == NULL)
			return;
		
		/**** 前序遍历位置 ****/
		left->next = right;

		// 连接相同父节点的两个子节点
		connectTwoNode(left->left, left->right);
		connectTwoNode(right->left, right->right);
		// 连接跨越父节点的两个子节点
		connectTwoNode(right->right, right->left);
	}
};