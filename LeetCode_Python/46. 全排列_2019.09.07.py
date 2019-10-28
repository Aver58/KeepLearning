""""
给定一个没有重复数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""
import itertools


class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if nums is None:
            return None
        # 1. 回溯 24ms 98.00%
        # res = []
        # def backtrack(nums, tmp):
        #     if not nums:
        #         res.append(tmp)
        #         return
        #     for i in range(len(nums)):
        #         # print(nums[:i], nums[i+1:], tmp+[nums[i]]) # 可以看到每一步的过程！！！
        #         backtrack(nums[:i] + nums[i+1:], tmp+[nums[i]])
        # backtrack(nums, [])
        # return res
        # 2.库函数 第一名  我发现力扣的时间是随机的
        return list(itertools.permutations(nums))


if __name__ == '__main__':
    candidates = [1,2,3]
    print(Solution().permute(candidates))
