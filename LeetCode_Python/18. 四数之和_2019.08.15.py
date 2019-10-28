""""
给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：

答案中不可以包含重复的四元组。

示例：

给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

满足要求的四元组集合为：
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/4sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""


class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        n = len(nums)
        if nums == None or target == None or n < 4:
            return []
        result_list = []
        nums.sort()
        for i in range(n - 3):
            # 防止重复 数组进入 res
            if i > 0 and nums[i] == nums[i-1]:
                continue
            # 当数组最小值和都大于target 跳出
            if nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target:
                break
            # 当数组最大值和都小于target,说明i这个数还是太小,遍历下一个
            if nums[i] + nums[n-1] + nums[n-2] + nums[n-3] < target:
                continue
            for j in range(i + 1, n - 2):
                # 防止重复 数组进入 res
                if j - (i + 1) > 0 and nums[j] == nums[j-1]:
                    continue
                # 同理
                if nums[i] + nums[j] + nums[j+1] + nums[j+2] > target:
                    break
                # 同理
                if nums[i] + nums[j] + nums[n-1] + nums[n-2] < target:
                    continue
                first = j + 1
                last = len(nums) - 1
                while first < last:
                    s = nums[i] + nums[j] + nums[first] + nums[last]
                    if s == target:
                        result_list.append([nums[i], nums[j], nums[first], nums[last]])
                        while first < last and nums[first] == nums[first+1]:
                            first += 1
                        while first < last and nums[last] == nums[last - 1]:
                            last -= 1
                        first += 1
                        last -= 1
                    elif s < target:
                        first += 1
                    else:
                        last -= 1
        return result_list


if __name__ == '__main__':
    nums = [0,0,0,0]
    target = 0
    node = Solution().fourSum(nums, target)
    print(node)
