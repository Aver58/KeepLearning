#pragma once
/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list.
If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Note:

Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-nodes-in-k-group
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include "Global.h"

class _25_Reverse_Nodes_in_k_Group
{
public:
	void Test() {
		ListNode* head = new ListNode(1);
		ListNode* head1 = new ListNode(2);
		ListNode* head2 = new ListNode(3);
		ListNode* head3 = new ListNode(4);
		ListNode* head4 = new ListNode(5);
		head->next = head1;
		head1->next = head2;
		head2->next = head3;
		head3->next = head4;
		_25_Reverse_Nodes_in_k_Group::reverseKGroup(head,2 );
	}

	ListNode* _reverseKGroup(ListNode* head, int k) {
		ListNode* pre = nullptr;
		ListNode* cur = head;
		ListNode* next = cur->next;
		//1. 将 cur 指向的下一节点保存到 next 指针；
		//2. curr 指向 pre，一起前进一步；
		//3. 重复之前步骤，直到 k 个元素翻转完毕；
		//4. 当完成了局部的翻转后，
		//	 pre 就是最终的新的链表头，
		//	 cur 指向了下一个要被处理的局部，
		//	 而原来的头指针 head 成为了链表的尾巴。
		for (int i = 0; i < k; i++)
		{
			next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		return pre->next;
	}


	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* dummy = new ListNode(0);
		dummy->next = head;

		ListNode* pre = dummy;
		ListNode* cur = NULL;
		ListNode* groupTail = NULL;// 组末尾
		ListNode* next = NULL;
		while (true)
		{
			// 1. 长度不够k的话不处理，不做该次循环
			int i = 1;
			groupTail = head;
			while (groupTail!=NULL && i < k)
			{
				i++;
				groupTail = groupTail->next;
			}

			if (groupTail == NULL) break;
		
			// 2. 翻转链表
			// 3. head 指向新的待翻转头
			head = _reverseKGroup(head, k);
		}
		return dummy->next;
	}
};

