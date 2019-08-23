"""
    问题：如何实现一个高效的单向链表逆序输出？
"""


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def reverse(self, head):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if head is None or head.next is None:
            return
        # 1. 递归 时间复杂度O(n),空间复杂度O(n)
        # self.reverse(head.next)
        # print(head.val)

        # 2. 栈 时间复杂度O(n),空间复杂度O(n)
        # stack = []
        # while head is not None:
        #     stack.append(head.val)
        #     head = head.next
        # for i in range(len(stack)):
        #     print(stack.pop())

        # 3.两次遍历 时间复杂度O(n^2),空间复杂度O(1)
        # 先计算总个数，然后一个一个输出
        # count = 0
        # tempHead = head
        # while tempHead is not None:
        #     tempHead = tempHead.next
        #     count += 1
        # for i in range(count, 0, -1):
        #     tempHead = head
        #     tempIndex = i
        #     while tempIndex - 1 is not 0:
        #         tempHead = tempHead.next
        #         tempIndex -= 1
        #     print(tempHead.val)

        # 4.翻转链表再遍历，但是需要改表表结构 时间复杂度O(n),空间复杂度O(1)
        # pre = ListNode(head.val)
        # cur = head.next
        # 翻转链表
        # while cur is not None:
        #     temp = cur.next # 先记住下一个节点
        #     cur.next = pre # 当前节点指向上一个节点
        #     pre = cur # 把前一个节点向后移动一位
        #     cur = temp  # 把当前节点向后移动一位
        # while pre is not None:
        #     print(pre.val)
        #     pre = pre.next

        # 5.头插法 时间复杂度O(n),空间复杂度O(n) todo

        # 6. what???
        # pre = None
        # cur = head.next
        # while cur is not None:
        #     if cur.next is None:
        #         cur.next = pre
        #         break
        #     next = cur.next
        #     cur.next = pre
        #     pre = cur
        #     cur = next
        #
        # head.next = cur
        # temp = head.next
        # while temp is not None:
        #     print(temp.val)
        #     temp = temp.next


if __name__ == '__main__':
    l1 = ListNode(1)
    l1.next = ListNode(2)
    Solution().reverse(l1)
