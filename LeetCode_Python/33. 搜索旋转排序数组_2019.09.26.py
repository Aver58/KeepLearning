""""
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

你可以假设数组中不存在重复的元素。

你的算法时间复杂度必须是 O(log n) 级别。

示例 1:

输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4
示例 2:

输入: nums = [4,5,6,7,0,1,2], target = 3
输出: -1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""


class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        # 1. 遍历 O(n) 36ms 78%
        # if target not in nums:
        #     return -1
        # else:
        #     for i in range(len(nums)):
        #         if nums[i] == target:
        #             return i

        # 你的算法时间复杂度必须是 O(log n) 级别。
        # 2. 二分法 28ms 97%
        # 遍历找到旋转交界，然后大于交界的，右边找，小于交界的左边找
        # 二分找到旋转边界
        def find_rotate_index():
            left, right = 0, n - 1
            if nums[left] < nums[right]:
                return 0

            while left <= right:
                pivot = (left + right) // 2
                if nums[pivot] > nums[pivot + 1]:
                    return pivot + 1
                else:
                    if nums[pivot] > nums[right]:
                        left = pivot
                    else:
                        right = pivot

        # 二分查找
        def search(left, right):
            while left <= right:
                pivot = (left + right) // 2
                if target == nums[pivot]:
                    return pivot
                else:
                    if target > nums[pivot]:
                        left = pivot + 1
                    else:
                        right = pivot - 1

            return -1

        n = len(nums)
        if n == 0:
            return -1
        elif n == 1:
            return 0 if target == nums[0] else -1

        rotate_index = find_rotate_index()

        if rotate_index == 0:
            return search(0, n - 1)

        if target < nums[0]:
            return search(rotate_index, n - 1)
        return search(0, rotate_index)


if __name__ == '__main__':
    nums = []
    target = 0
    print(Solution().search(nums, target))
