""""
给定一个 n × n 的二维矩阵表示一个图像。

将图像顺时针旋转 90 度。

说明：

你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。

示例 1:

给定 matrix =
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
示例 2:

给定 matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
],

原地旋转输入矩阵，使其变为:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotate-image
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""


class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        # 方法 1 ：转置加翻转 24 ms 87%
        # 我的猪脑袋想不出来，就是沿着对角线翻转，再镜像，就是我们想要的效果
        # if matrix is None:
        #     return None
        # n = len(matrix[0])
        # # 沿着对角线翻转矩阵
        # for i in range(n):
        #     for j in range(i, n):
        #         matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        # # 镜像翻转每一行
        # for i in range(n):
        #     matrix[i].reverse()

        # 方法 2 ：旋转四个矩形,
        # 借助一个额外空间tmp列表，一次旋转4个对象
        # n = len(matrix[0])
        # for i in range(n // 2 + n % 2):
        #     for j in range(n // 2):
        #         tmp = [0] * 4
        #         row, col = i, j
        #         # store 4 elements in tmp
        #         for k in range(4):
        #             tmp[k] = matrix[row][col]
        #             row, col = col, n - 1 - row
        #         # rotate 4 elements
        #         for k in range(4):
        #             matrix[row][col] = tmp[(k - 1) % 4]
        #             row, col = col, n - 1 - row

        # 方法 3：在单次循环中旋转 4 个矩形 20ms 96.5%
        # 借助一个额外空间tmp，一次旋转4个对象
        n = len(matrix[0])
        # 外循环：0-中点，奇数的话需要+1
        for i in range(n // 2 + n % 2):
            # 内循环0-中点，中心点不管是奇数还是偶数都不旋转
            for j in range(n // 2):
                # 顺时针交换值
                tmp = matrix[n - 1 - j][i]
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - j - 1]
                matrix[n - 1 - i][n - j - 1] = matrix[j][n - 1 -i]
                matrix[j][n - 1 - i] = matrix[i][j]
                matrix[i][j] = tmp


if __name__ == '__main__':
    matrix =[
        [1,2,3],
        [4,5,6],
        [7,8,9]
    ]
    Solution().rotate(matrix)
    print(matrix)
