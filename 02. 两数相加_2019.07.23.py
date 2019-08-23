""""
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

"""


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        # 考察链表使用，注意进位和最后进位的情况，
        # 执行用时 :
        # 64 ms, 在所有 Python 提交中击败了72.39%的用户
        # 内存消耗 :
        # 11.8 MB, 在所有 Python 提交中击败了29.57%的用户
        dummyHead = ListNode(0) # 哑节点
        result = dummyHead
        carry = 0 # 作为上一次相加是否需要进1的依据
        while l1 or l2:
            # 这里多判断了很多次l1和l2是否为空
            s = 0
            if l1:
                s += l1.val
                l1 = l1.next

            if l2:
                s += l2.val
                l2 = l2.next

            s += carry
            carry = s // 10
            result.next = ListNode(s % 10)
            result = result.next

        # 如果进位了要再输出一位
        if carry > 0:
            result.next = ListNode(carry)
        return dummyHead.next


if __name__ == '__main__':
    l1 = ListNode(1)
    l1.next = ListNode(2)
    l2 = ListNode(1)
    l2.next = ListNode(3)
    node = Solution().addTwoNumbers(l1, l2)
    while node:
        print(node.val)
        node = node.next
