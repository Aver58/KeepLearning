""""
将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-two-sorted-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if l1 is None and l2 is None:
            return None
        if l1 and not l2:
            return l1
        if l2 and not l1:
            return l2

        dummy = ListNode(0)
        result = dummy
        # 有序链表
        # 1. 双指针 ，考察链表
        # 复杂度分析：
        # 时间复杂度：O(l1 + l2) --16ms 击败了99.68%
        # 空间复杂度：O(l1 + l2) -- 11.8M 击败 19.8%
        p1, p2 = l1, l2
        while p1 or p2:
            if not p1:
                result.next = ListNode(p2.val)
                p2 = p2.next
            elif not p2:
                result.next = ListNode(p1.val)
                p1 = p1.next
            elif p1.val >= p2.val:
                result.next = ListNode(p2.val)
                p2 = p2.next
            else:
                result.next = ListNode(p1.val)
                p1 = p1.next
            result = result.next
        #
        # return dummy.next
        # 2. 递归
        # 时间复杂度：O(n) --16ms 击败了99.68%
        # 空间复杂度：O(l1+l2) -- 11.8M 击败 19.8%
        if not l1:
            return l2
        if not l2:
            return l1
        if l1.val < l2.val:
            l1.next = self.mergeTwoLists(l1.next, l2)
        else:
            l2.next = self.mergeTwoLists(l1, l2.next)

        return l1


if __name__ == '__main__':
    l1 = ListNode(1)
    l2 = ListNode(2)
    head2 = ListNode(2)
    head3 = ListNode(3)
    head4 = ListNode(4)
    head5 = ListNode(5)

    l1.next = head2
    l2.next = head2
    head2.next = head3
    head3.next = head4
    head4.next = head5

    node = Solution().mergeTwoLists(l1, l2)
    print(node.val)
