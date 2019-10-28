""""
给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在众数。

示例 1:

输入: [3,2,3]
输出: 3
示例 2:

输入: [2,2,1,1,1,2,2]
输出: 2

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/majority-element
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""


class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 1. 哈希法 164 ms 97%
        # 时间复杂度：O(n)空间复杂度：O(n)
        # numMap = {}
        # for num in nums:
        #     if num in numMap:
        #         numMap[num] += 1
        #     else:
        #         numMap[num] = 1
        # maxTimes = 0
        # retNum = 0
        # for k, v in numMap.items():
        #     if maxTimes < v:
        #         retNum = k
        #         maxTimes = v
        # return retNum

        # 2. 排序 204ms 57%
        # 时间复杂度：O(nlgn)
        nums.sort()
        return nums[len(nums)//2]

if __name__ == '__main__':
    nums = [3,3,4]
    print(Solution().majorityElement(nums))
