""""
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。
找出 nums 中的三个整数，使得它们的和与 target 最接近。
返回这三个数的和。假定每组输入只存在唯一答案。

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).

"""


class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if nums==None or len(nums) < 3:
            return []
        nums.sort()

        diff = float('inf')
        closest = nums[0] + nums[1] +nums[2]
        for i in range(len(nums) - 2):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            first = i + 1
            last = len(nums) - 1
            while first < last:
                sum = nums[first] + nums[i] +nums[last]
                if abs(target - sum) < diff:
                    diff = abs(sum - target)
                    closest = sum

                if sum > target:
                    last -= 1
                elif sum < target:
                    first += 1
                else:
                    return target

        return closest


if __name__ == '__main__':
    nums = [-1,2,1,-4]
    target = 1
    node = Solution().threeSumClosest(nums, target)
    print(node)
