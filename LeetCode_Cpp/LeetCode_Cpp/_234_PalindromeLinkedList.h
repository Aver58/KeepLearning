#pragma once
/*
Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/palindrome-linked-list
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

#include "Global.h"

class _234_PalindromeLinkedList
{
public:
	static void Test() {
		ListNode* head = new ListNode(1);
		ListNode* head1 = new ListNode(2);
		ListNode* head2 = new ListNode(2);
		ListNode* head3 = new ListNode(1);
		head->next = head1;
		head1->next = head2;
		head2->next = head3;
		std::cout << _234_PalindromeLinkedList::isPalindrome(head);
	}

	static bool isPalindrome(ListNode* head) {
		//1. ����ָ���ҳ��е�
		//��ת��벿��
		//�ٱȽ�ǰ�������Ƿ���ͬ
		if (head == nullptr) return true;
		if (head->next == nullptr) return true;
		ListNode* slow = head;
		ListNode* fast = head;
		ListNode* pre = nullptr;
		//find mid node
		while (fast)
		{
			slow = slow->next;
			fast = fast->next->next;
		}

		//reverse right half part 
		while (slow) {
			ListNode* temp = slow->next;
			slow->next = pre;
			pre = slow;
			slow = temp;
		}

		// check
		while (head && pre)
		{
			if (head->val != pre->val)
			{
				return false;
			}
			head = head->next;
			pre = pre->next;
		}
		return true;
	}
};

