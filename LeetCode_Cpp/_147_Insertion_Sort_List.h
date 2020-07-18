#pragma once
/*
Sort a linked list using insertion sort.


A graphical example of insertion sort. The partial sorted list (black) initially contains only the first element in the list.
With each iteration one element (red) is removed from the input data and inserted in-place into the sorted list
 

Algorithm of Insertion Sort:

1. Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
2. At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, 
	and inserts it there.
3. It repeats until no input elements remain.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/insertion-sort-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include "Global.h"

class _147_Insertion_Sort_List
{
public:
	void Test() {
		ListNode* head = new ListNode(-1);
		ListNode* head1 = new ListNode(5);
		ListNode* head2 = new ListNode(3);
		ListNode* head3 = new ListNode(4);
		ListNode* head4 = new ListNode(0);
		head->next = head1;
		head1->next = head2;
		head2->next = head3;
		head3->next = head4;
		ListNode* res = insertionSortList(head);
		while (res)
		{
			cout << res->val;
			res = res->next;
		}
	}

	ListNode* insertionSortList(ListNode* head) {
		//使用插入排序排列這個鏈錶
		if (head == NULL ||head->next == NULL)
			return head;
		//1. 暴力法 65%
		ListNode* dummy = new ListNode(0);
		while (head) {
			//找到比head小的节点pre
			ListNode* pre = dummy;
			while (pre->next && pre->next->val < head->val) 
				pre = pre->next;

			// 把pre接到head前面
			ListNode* cur = head;
			head = head->next;

			cur->next = pre->next;
			pre->next = cur;
		}
		return dummy->next;

		//2. 
		//ListNode* dummy = new ListNode(-1);
		//dummy->next = head;
		//ListNode* pre = dummy;
		// 分两部分，一部分已排好序，一部分未排序
		//while (head != NULL && head->next != NULL) 
		//{
		//	// 找到不是升序的节点head
		//	if (head->val <= head->next->val) 
		//	{
		//		head = head->next;
		//		continue;
		//	}
		//	// 从头开始遍历，找到该节点的插入位置
		//	pre = dummy;
		//	while (pre->next->val <= head->next->val) 
		//	{
		//		pre = pre->next;
		//	}
		//	ListNode* cur;
		//	cur = head->next;
		//	head->next = cur->next;
		//	cur->next = pre->next;
		//	pre->next = cur;
		//}
		//return dummy->next;
	}
};

