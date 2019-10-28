""""
反转一个单链表。

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
"""


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        # 1. 借助栈，压栈弹出后就是反转列表

        # 2. 借助3个变量（pre、cur、temp）实现，遍历 28ms 72%
        # pre, cur = None, head
        # while cur:
        #     temp = cur.next
        #     cur.next = pre
        #     pre = cur
        #     cur = temp
        # return pre

        # 3. 递归 36ms 31.93%
        # 最开始 1 -> 2 -> 3 -> 4
        # 对于head.next.next = head , 当head在 3 时，相当于加了一个4 -> 3 ，形成回环, 即 1 -> 2 -> 3 <-> 4
        # 然后 head.next = None, 取消回环，消除了 3 -> 4
        # 1 -> 2 -> 3 <- 4

        # if head is None or head.next is None:
        #     # 拿到最后一个元素
        #     return head
        # ptr = self.reverseList(head.next)
        # head.next.next = head
        # head.next = None
        # return ptr
        # 第一名
        while head:
            cur = head.next
            head.next = pre
            pre = head
            head = cur
        return pre

if __name__ == '__main__':
    nums = [1,2,3,1]
    print(Solution().reverseList(nums))
