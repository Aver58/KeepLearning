"""
两数之和
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
"""


class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        # not 0 == True!!!
        if not nums:
            return
        """
        # 方法一、暴力解法：
        # 复杂度分析：时间复杂度：O(n^2)空间复杂度：O(1) -- 5s
        length = len(nums)
        for i in range(length):
            for j in range(i + 1, length):
                if nums[i] + nums[j] == target:
                    return [i, j]
                    
        # 方法二：利用python切片。 其实原理跟2次遍历一样
        # 解题关键主要是想找到 num2 = target - num1，是否也在list中，- 1s
        for i in range(len(nums)):
            if target-nums[i] in nums[i+1:]:
                return [i, nums.index(target-nums[i], i+1)]
        """

        # 方法三、直接哈希记录需要的key，遍历到就是找到需要的值： -- 80ms
        # 复杂度分析：时间复杂度：O(n)空间复杂度：O(n)
        dic = {}
        for i, num in enumerate(nums):
            if num in dic:
                return [dic[num], i]
            else:
                dic[target - num] = i


if __name__ == '__main__':
    nums = [0, 4, 3, 0]
    target = 0
    print(Solution().twoSum(nums, target))
