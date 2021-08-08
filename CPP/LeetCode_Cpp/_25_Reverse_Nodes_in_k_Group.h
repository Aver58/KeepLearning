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

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/reverse-nodes-in-k-group
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
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
		//1. �� cur ָ�����һ�ڵ㱣�浽 next ָ�룻
		//2. curr ָ�� pre��һ��ǰ��һ����
		//3. �ظ�֮ǰ���裬ֱ�� k ��Ԫ�ط�ת��ϣ�
		//4. ������˾ֲ��ķ�ת��
		//	 pre �������յ��µ�����ͷ��
		//	 cur ָ������һ��Ҫ������ľֲ���
		//	 ��ԭ����ͷָ�� head ��Ϊ�������β�͡�
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
		ListNode* groupTail = NULL;// ��ĩβ
		ListNode* next = NULL;
		while (true)
		{
			// 1. ���Ȳ���k�Ļ������������ô�ѭ��
			int i = 1;
			groupTail = head;
			while (groupTail!=NULL && i < k)
			{
				i++;
				groupTail = groupTail->next;
			}

			if (groupTail == NULL) break;
		
			// 2. ��ת����
			// 3. head ָ���µĴ���תͷ
			head = _reverseKGroup(head, k);
		}
		return dummy->next;
	}
};

