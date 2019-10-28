""""
给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。

图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。

示例:

输入: [1,8,6,2,5,4,8,3,7]
输出: 49

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/container-with-most-water
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""


class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        if height is None:
            return 0
        maxArea = 0
        # 1. 暴力法 O(n^2) 超出时间限制
        # for i in range(len(height)):
        #     for j in range(len(height)):
        #         maxArea = max(maxArea, abs(i - j) * min(height[i],height[j]))
        # return maxArea
        # 2. 双指针 O（n）124 ms  93%
        # 错误思路：慢指针指向最高的，快指针指向第二高的，
        # 正确思路：求出所有面积，每次求面积都用矮的求
        left, right = 0, len(height) - 1
        while left < right:
            maxArea = max(maxArea, abs(right - left) * min(height[right], height[left]))
            if height[right] > height[left]:
                left += 1
            else:
                right -= 1
        return maxArea


if __name__ == '__main__':
    nums1 = [1,8,6,2,5,4,8,3,7]
    node = Solution().maxArea(nums1)
    print(node)
