""""
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]

固定三个数字中最左数字的指针 k，遍历 k 找到每个k对应的所有满足nums[k] + nums[i] + nums[j] == 0的 i,j 组合。即每指向新的 nums[k]，都通过双指针法找到所有和为 00 的 nums[i]，nums[j] 并记录：

当 nums[k] > 0 时直接跳出，因为 j > i > k，即三个数字都大于 00，在此k之后不可能找到组合了；
当 k > 0且nums[k] == nums[k - 1]时跳过此数字k，因为 nums[k - 1] 的所有组合已经被加入到结果中，本次搜索只会搜索到重复组合。
i，j 分设在数组 [k, len(nums)] 两端，根据 sum 与 00 的大小关系交替向中间逼近，如果遇到等于 00 的组合则加入 res 中，需要注意：
移动 i，j 需要跳过所有重复值，以避免重复答案被计入 res。
整体算法复杂度 O(n2)O(n2)。

"""


class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        # 1. n^3
        # resultList = []
        # if nums == None or len(nums) < 3:
        #     return resultList
        # for i in range(len(nums)-2):
        #     for j in range(i+1, len(nums)-1):
        #         for k in range(j+1, len(nums)):
        #             if nums[i] + nums[j] + nums[k] == 0:
        #                 resultList.append([nums[i], nums[j], nums[k]])

        # 2. 双指针
        # 选一个组合最左的数字k（相当于循环列表），用i，j双指针去移动构成组合
        nums.sort()
        resultList = []
        for first in range(len(nums) - 2):
            if nums[first] > 0:
                break # because of j > i > k.
            if first > 0 and nums[first] == nums[first - 1]:
                continue # skip.去重

            # k 最左，i是中间，j最右
            i = first + 1
            last = len(nums) - 1
            while i < last:
                s = nums[i] + nums[last] + nums[first]
                if s == 0:
                    resultList.append([nums[i], nums[last], nums[first]])
                    i += 1
                    last -= 1
                    while i < last and nums[i] == nums[i - 1]:
                        i += 1
                    while i < last and nums[last] == nums[last + 1]:
                        last -= 1
                elif s < 0:
                    i += 1
                    while i < last and nums[i] == nums[i - 1]:
                        i += 1
                else:
                    last -= 1
                    while i < last and nums[last] == nums[last + 1]:
                        last -= 1
        return resultList

# [[-4,-2,6],[-4,0,4],[-4,1,3],[-4,2,2],[-2,-2,4],[-2,0,2]]
if __name__ == '__main__':
    nums1 = [-1,0,1,2,-1,-4]
    node = Solution().threeSum(nums1)
    print(node)
