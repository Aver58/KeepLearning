""""
给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-depth-of-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        # 1. 回溯 36 ms 75%
        # 试探树的所有节点，取得最大值
        # def _maxDepth(node, depth, maxDepth):
        #     if node is None:
        #         return max(depth, maxDepth)
        #     depth += 1
        #     maxDepth = _maxDepth(node.left, depth, maxDepth)
        #     maxDepth = _maxDepth(node.right, depth, maxDepth)
        #     return maxDepth
        #
        # return _maxDepth(root, 0, 0)

        # 2. 迭代 56 ms 15%
        # 借助栈实现
        stack = []
        if root is not None:
            stack.append((1, root))

        depth = 0
        while stack != []:
            current_depth, root = stack.pop()
            if root is not None:
                depth = max(depth, current_depth)
                stack.append((current_depth + 1, root.left))
                stack.append((current_depth + 1, root.right))

        return depth


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
    print(Solution().maxDepth(head))
