""""
实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

必须原地修改，只允许使用额外常数空间。

以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/next-permutation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""


class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        # 所有的文字我都认识，连在一起我就不认识了。
        # 思路：最简单的思路，就是将其当做一个十进制的数去理解，找出比当前十进制数大的下一位，
        # 比如12354，下一个就是12435。
        #源于离散数学及其应用的算法：
        # （以1 2 3 5 4 为例）
        #从后往前寻找第一次出现的正序对：（找到 3,5）
        #之后因为从 5 开始都是逆序，所以把他们反转就是正序：1 2 3 4 5
        #之后 3 的位置应该是：在它之后的，比他大的最小值（4）
        #交换这两个值：得到 1 2 4 3 5

        if len(nums) < 2:
            return
        i = len(nums)-1
        while i > 0 and nums[i] <= nums[i-1]:
            i -= 1
        a, b = i, len(nums)-1
        while a < b:
            nums[a], nums[b] = nums[b], nums[a]
            a += 1
            b -= 1

        j = i-1
        for k in range(i, len(nums)):
            if nums[k] > nums[j]:
                nums[j], nums[k] = nums[k], nums[j]
                break

        # 对于初始即为逆序的序列，将在反转步骤直接完成
        # if len(nums)<2:
        #     return
        # i=len(nums)-1

        # 1. 快慢指针法 n
        # def reverse(nums, i, j):
        #     while i < j:
        #         nums[i], nums[j] = nums[j], nums[i]
        #         i += 1
        #         j -= 1
        # n = len(nums)
        # firstIndex = -1
        # for i in range(n-2, -1, -1):
        #     if nums[i] < nums[i+1]:
        #         firstIndex = i
        #         break
        # print(firstIndex)
        # if firstIndex == -1:
        #     # 如果已经是降序，返回升序
        #     reverse(nums, 0, n-1)
        #     return
        #
        # secondIndex = -1
        # for i in range(n-1, firstIndex, -1):
        #     if nums[i] > nums[firstIndex]:
        #         secondIndex = i
        #         break
        # print(secondIndex)
        # nums[firstIndex], nums[secondIndex] = nums[secondIndex], nums[firstIndex]
        # reverse(nums, firstIndex+1, n-1)

        # 第一名
        if not nums:
            return []

        i = 0
        j = len(nums)-1
        while i < j:
            if nums[j-1] >= nums[j]:
                # 找到第一个正序对的索引
                j -= 1
            else:
                break

        if j == 0:
            # 数组是降序的
            nums.reverse()
            return nums

        i = j - 1
        while j < len(nums):
            if nums[j] > nums[i]:
                # 找到比nums[i]大的最小值索引
                j += 1
            else:
                break

        # 交换 i 和 j - 1
        nums[i], nums[j-1] = nums[j-1], nums[i]
        # 反转降序对
        j = len(nums)-1
        i += 1
        while i < j:
            nums[i], nums[j] = nums[j], nums[i]
            i += 1
            j -= 1

        return nums


if __name__ == '__main__':
    nums = [2, 4, 5, 3, 1]
    Solution().nextPermutation(nums)
    print(nums)