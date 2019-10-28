""""
翻转一棵二叉树。

示例：

输入：

     4
   /   \
  2     7
 / \   / \
1   3 6   9
输出：

     4
   /   \
  7     2
 / \   / \
9   6 3   1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/invert-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def invertTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        # 1. 递归 24 ms 54%
        # if root is None:
        #     return None
        # left = self.invertTree(root.left)
        # right = self.invertTree(root.right)
        # root.left = right
        # root.right = left
        # return root
        # 2. 迭代
        # 建一个队列来存储所有左孩子和右孩子还没有被交换过的节点
        # 只要这个队列不空，就一直从队列中出队节点，然后互换这个节点的左右孩子节点，
        # 接着再把孩子节点入队到队列。
        queue = []
        queue.append(root)
        while len(queue) > 0:
            item = queue.pop()
            temp = item.left
            item.left = item.right
            item.right = temp
            if item.left is not None:
                queue.append(item.left)
            if item.right is not None:
                queue.append(item.right)
        return root


if __name__ == '__main__':
    root = TreeNode(4)
    root1 = TreeNode(2)
    root2 = TreeNode(7)
    root3 = TreeNode(9)
    root4 = TreeNode(6)
    root5 = TreeNode(3)
    root6 = TreeNode(1)
    root.left = root1
    root.right = root2
    root1.left = root6
    root1.right = root5
    root2.left = root4
    root2.right = root3
    print(Solution().invertTree(root))
