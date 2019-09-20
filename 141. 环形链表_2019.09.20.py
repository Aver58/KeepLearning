""""
给定一个链表，判断链表中是否有环。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

 

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
        # 方法一：哈希表
        # 我们遍历所有结点并在哈希表中存储每个结点的引用（或内存地址）。
        # 如果当前结点为空结点 null（即已检测到链表尾部的下一个结点），那么我们已经遍历完整个链表，并且该链表不是环形链表。
        # 如果当前结点的引用已经存在于哈希表中，那么返回 true（即该链表为环形链表）。
        


if __name__ == '__main__':
    # target = [1,2,2,3,4,4,3]
    head = TreeNode(1)

    head1 = TreeNode(2)
    head1.left = TreeNode(3)
    head1.right = TreeNode(4)

    head3 = TreeNode(2)
    head3.left = TreeNode(4)
    head3.right = TreeNode(3)

    head2 = TreeNode(2)
    head2.left = head3
    head2.right = TreeNode(3)

    head.left = head1
    head.right = head2

    pos = -1
    print(Solution().hasCycle(head))
