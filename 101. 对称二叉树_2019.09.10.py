""""
给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3

说明:

如果你可以运用递归和迭代两种方法解决这个问题，会很加分。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/symmetric-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        # 1. 递归 构造一棵树跟自己比较 40 ms 15%
        # 时间复杂度：O(n) 空间复杂度为 O(n)
        # 它们的两个根结点具有相同的值。
        # 每个树的右子树都与另一个树的左子树镜像对称。
        # def _isSymmetric(left, right):
        #     if left is None and right is None:
        #         return True
        #     if left is None or right is None:
        #         return False
        #     return left.val == right.val and _isSymmetric(left.left, right.right) and _isSymmetric(left.right, right.left)
        #
        # return _isSymmetric(root, root)

        # 2. 迭代 32ms 42%
        # 时间复杂度：O(n) 空间复杂度为 O(n)
        # 利用队列进行迭代:每次进栈2个队列，所以连续2个数
        # Queue = []
        # Queue.append(root)
        # Queue.append(root)
        # while len(Queue) > 0:
        #     node1 = Queue.pop(0)
        #     node2 = Queue.pop(0)
        #     # 如果两个节点都是空，该分支对称，继续树的其他分支
        #     if node1 is None and node2 is None:
        #         continue
        #     # 如果有一个节点是空，一个不是空，那么肯定不对称
        #     if node1 is None or node2 is None:
        #         return False
        #     if node1.val != node2.val:
        #         return False
        #     Queue.append(node1.left)
        #     Queue.append(node2.right)
        #     Queue.append(node1.right)
        #     Queue.append(node2.left)
        # return True

        # 12ms
        def readL(node, res):
            if node==None:
                res.append(None)
                return
            res.append(node.val)
            readL(node.left, res)
            readL(node.right, res)

        def readR(node, res):
            if node==None:
                res.append(None)
                return
            res.append(node.val)
            readR(node.right, res)
            readR(node.left, res)

        resL = []
        resR = []
        readL(root, resL)
        readR(root, resR)

        return resL==resR

if __name__ == '__main__':
    # target = [1,2,2,3,4,4,3]
    head = TreeNode(1)
    head1 = TreeNode(2)
    head1.left = TreeNode(3)
    head1.right = TreeNode(4)
    head2 = TreeNode(2)
    head2.left = TreeNode(4)
    head2.right = TreeNode(3)
    head.left = head1
    head.right = head2
    print(Solution().isSymmetric(head))
