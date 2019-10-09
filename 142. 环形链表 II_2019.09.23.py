""""
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

说明：不允许修改给定的链表。

示例 1：

输入：head = [3,2,0,-4], pos = 1
输出：true
解释：链表中有一个环，其尾部连接到第二个节点。

示例 2：

输入：head = [1,2], pos = 0
输出：true
解释：链表中有一个环，其尾部连接到第一个节点。

示例 3：

输入：head = [1], pos = -1
输出：false
解释：链表中没有环。

进阶：
你是否可以不用额外空间解决此题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/linked-list-cycle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""


# Definition for singly-linked list.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        # 不允许修改给定的链表。

        # 1: 哈希表, 空间复杂度O(n) 48 ms 73%
        # 返回第一个重复的值
        # dummy = head
        # tmpMap = set()
        # while dummy:
        #     if dummy in tmpMap:
        #         return dummy
        #     else:
        #         tmpMap.add(dummy)
        #     dummy = dummy.next
        # return None

        # 你是否可以不用额外空间解决此题？
        # 2. 快慢指针
        # https://leetcode-cn.com/problems/linked-list-cycle-ii/solution/huan-xing-lian-biao-ii-by-leetcode/
        # Floyd 算法
        # 在第一阶段，找出列表中是否有环，如果没有环，可以直接返回 null 并退出。
        # 否则，进入第二阶段，用 相遇节点 来找到环的入口。
        def getIntersect(head):
            tortoise = head
            hare = head

            # 这里我们初始化两个指针 - 快指针和慢指针。
            # 我们每次移动慢指针一步、快指针两步，直到快指针无法继续往前移动。
            while hare is not None and hare.next is not None:
                tortoise = tortoise.next
                hare = hare.next.next
                if tortoise == hare:
                    return tortoise

            return None

        def detectCycle(head):
            if head is None:
                return None

            # 如果在某次移动后，快慢指针指向了同一个节点，我们就返回它。
            # 否则，我们继续，直到 while 循环终止且没有返回任何节点，这种情况说明没有成环，我们返回 null 。
            intersect =getIntersect(head)
            if intersect is None:
                return None

            # 给定阶段 1 找到的相遇点，阶段 2 将找到环的入口。
            # 首先我们初始化额外的两个指针： ptr1 ，指向链表的头， ptr2 指向相遇点。
            # 然后，我们每次将它们往前移动一步，直到它们相遇，它们相遇的点就是环的入口，返回这个节点。
            ptr1 = head
            ptr2 = intersect
            while ptr1 != ptr2:
                ptr1 = ptr1.next
                ptr2 = ptr2.next

            return ptr1


if __name__ == '__main__':
    head = TreeNode(3)

    head1 = TreeNode(2)
    head.next = head1

    head2 = TreeNode(0)
    head1.next = head2

    head3 = TreeNode(4)
    head2.next = head1

    print(Solution().hasCycle(head))
