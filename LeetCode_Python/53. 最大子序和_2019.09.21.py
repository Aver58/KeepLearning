""""
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
进阶:

如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""


class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 1. 动态规划 O(n)
        # 用一个临时值temp来保存每次子串的和
        # 如果子串的和加上当前值小于当前值，
        # 那么就用当前值作为新的子串开始位置，继续遍历
        # if nums is None or len(nums) <= 0:
        #     return None
        # res = nums[0]
        # temp = 0
        # for num in nums:
        #     temp = max(temp + num, num)
        #     if temp > res:
        #         res = temp
        # return res

        # 2. 分治法
        # 它的最大子序和要么在左半边，要么在右半边，要么是穿过中间，
        # 对于左右边的序列，情况也是一样，因此可以用递归处理。
        # 中间部分的则可以直接计算出来



if __name__ == '__main__':
    candidates = [-2,1,-3,4,-1,2,1,-5,4]
    print(Solution().maxSubArray(candidates))
