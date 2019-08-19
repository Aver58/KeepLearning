""""
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：

给定的 n 保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        # 1. 遍历所有节点，记录长度length，然后第二次遍历，访问指定头部
        # 时间复杂度：O(2L - n)空间复杂度：O(1)O(1)

        # if head is None:
        #     return head
        # pointer = head
        # length = 0
        # while pointer.next is not None:
        #     length += 1
        #     pointer = pointer.next
        # if n > length:
        #     return head
        # pointer = head
        # for i in range(length - n - 1):
        #     pointer = pointer.next
        # pointer.next = pointer.next.next
        # return head

        # 2. 快慢指针，我理解的话还是滑动窗口，两个指针相隔n的距离，然后快指针走完，慢指针就是倒数第n个节点
        # 动画实现https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/solution/dong-hua-tu-jie-leetcode-di-19-hao-wen-ti-shan-chu/
        # 为什么需要哑节点？因为如果没有哑结点的话，对于整个链表为空的情况就会很难处理。
        #   比如说，链表只有一个结点，并且需要删除这个节点。如果只有head，是很难处理的。
        #   如果设置了dummy.next = head，就可以设置dummy.next = None同时返回dummy.next
        dummy = ListNode(0)
        dummy.next = head
        fastPointer, slowPointer = dummy, dummy
        for i in range(n + 1):
            fastPointer = fastPointer.next
        while fastPointer is not None:
            fastPointer = fastPointer.next
            slowPointer = slowPointer.next
        slowPointer.next = slowPointer.next.next
        return dummy.next


if __name__ == '__main__':
    head = ListNode(1)
    head2 = ListNode(2)
    head3 = ListNode(3)
    head4 = ListNode(4)
    head5 = ListNode(5)

    head.next = head2
    head2.next = head3
    head3.next = head4
    head4.next = head5
    n = 2
    node = Solution().removeNthFromEnd(head, n)
    print(node)
