""""
5072. 最多可以买到的苹果数量

楼下水果店正在促销，你打算买些苹果，arr[i] 表示第 i 个苹果的单位重量。

你有一个购物袋，最多可以装 5000 单位重量的东西，算一算，最多可以往购物袋里装入多少苹果。
示例 1：

输入：arr = [100,200,150,1000]
输出：4
解释：所有 4 个苹果都可以装进去，因为它们的重量之和为 1450。
示例 2：

输入：arr = [900,950,800,1000,700,800]
输出：5
解释：6 个苹果的总重量超过了 5000，所以我们只能从中任选 5 个。

提示：

1 <= arr.length <= 10^3
1 <= arr[i] <= 10^3
"""


# class Solution(object):
#     def maxNumberOfApples(self, arr):
#         """
#         :type arr: List[int]
#         :rtype: int
#         """
#         # 1. 排序一下，超重就不加了
#         if arr is None:
#             return None
#         arr.sort()
#         n = len(arr)
#         weight = 0
#         for i in range(n):
#             if weight + arr[i] < 5000:
#                 weight += arr[i]
#             else:
#                 return i
#         return n


""""
5073. 进击的骑士

一个坐标可以从 -infinity 延伸到 +infinity 的 无限大的 棋盘上，你的 骑士 驻扎在坐标为 [0, 0] 的方格里。

骑士的走法和中国象棋中的马相似，走 “日” 字：即先向左（或右）走 1 格，再向上（或下）走 2 格；或先向左（或右）走 2 格，再向上（或下）走 1 格。

每次移动，他都可以按图示八个方向之一前进。



现在，骑士需要前去征服坐标为 [x, y] 的部落，请你为他规划路线。

最后返回所需的最小移动次数即可。本题确保答案是一定存在的。

 

示例 1：

输入：x = 2, y = 1
输出：1
解释：[0, 0] → [2, 1]
示例 2：

输入：x = 5, y = 5
输出：4
解释：[0, 0] → [2, 1] → [4, 2] → [3, 4] → [5, 5]
 

提示：

|x| + |y| <= 300
"""


class Solution(object):
    def minKnightMoves(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """


""""
5071. 找出所有行中最小公共元素

给你一个矩阵 mat，其中每一行的元素都已经按 递增 顺序排好了。请你帮忙找出在所有这些行中 最小的公共元素。

如果矩阵中没有这样的公共元素，就请返回 -1。

 

示例：

输入：mat = [[1,2,3,4,5],[2,4,5,8,10],[3,5,7,9,11],[1,3,5,7,9]]
输出：5
 

提示：

1 <= mat.length, mat[i].length <= 500
1 <= mat[i][j] <= 10^4
mat[i] 已按递增顺序排列。
"""

# class Solution(object):
#     def smallestCommonElement(self, mat):
#         """
#         :type mat: List[List[int]]
#         :rtype: int
#         """
#         if mat is None:
#             return None
        # 1. 暴力法
        # 找到开头最大的行，然后遍历该行，
        # 找到大家都拥有的元素
        # 递归，回溯

        # 2. 做个字典，
        # 然后遍历第一行，如果大家都有，返回该值
        # for i in mat[0]:
        #     isMatch = True
        #     for row in mat:
        #         if i not in row:
        #             isMatch = False
        #             break
        #     if isMatch:
        #         return i
        # return -1


""""
5091. 建造街区的最短时间

你是个城市规划工作者，手里负责管辖一系列的街区。在这个街区列表中 blocks[i] = t 意味着第  i 个街区需要 t 个单位的时间来建造。

由于一个街区只能由一个工人来完成建造。

所以，一个工人要么需要再召唤一个工人（工人数增加 1）；要么建造完一个街区后回家。这两个决定都需要花费一定的时间。

一个工人再召唤一个工人所花费的时间由整数 split 给出。

注意：如果两个工人同时召唤别的工人，那么他们的行为是并行的，所以时间花费仍然是 split。

最开始的时候只有 一个 工人，请你最后输出建造完所有街区所需要的最少时间。

 

示例 1：

输入：blocks = [1], split = 1
输出：1
解释：我们使用 1 个工人在 1 个时间单位内来建完 1 个街区。
示例 2：

输入：blocks = [1,2], split = 5
输出：7
解释：我们用 5 个时间单位将这个工人分裂为 2 个工人，然后指派每个工人分别去建造街区，从而时间花费为 5 + max(1, 2) = 7
示例 3：

输入：blocks = [1,2,3], split = 1
输出：4
解释：
将 1 个工人分裂为 2 个工人，然后指派第一个工人去建造最后一个街区，并将第二个工人分裂为 2 个工人。
然后，用这两个未分派的工人分别去建造前两个街区。
时间花费为 1 + max(3, 1 + max(1, 2)) = 4
 

提示：

1 <= blocks.length <= 1000
1 <= blocks[i] <= 10^5
1 <= split <= 100
"""


# class Solution(object):
#     def minBuildTime(self, blocks, split):
#         """
#         :type blocks: List[int]
#         :type split: int
#         :rtype: int
#         """
        # n = len(blocks)
        # if blocks is None or n <= 0:
        #     return 0
        # if n <= 1:
        #     return 1
        # return split + max(blocks[-1], self.minBuildTime(blocks[:n - 1], split))


if __name__ == '__main__':
    x = 2
    y = 1
    print(Solution().minKnightMoves(x, y))
    # mat = [[1,2,3,4,5],[2,4,5,8,10],[3,5,7,9,11],[1,3,5,7,9]]
    # print(Solution().smallestCommonElement(mat))
    # blocks = [1,1,1,1]
    # split = 100
    # print(Solution().minBuildTime(blocks, split))
