""""
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:

输入: [2,2,3,2]
输出: 3
示例 2:

输入: [0,1,0,1,0,1,99]
输出: 99

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/single-number-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""


class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 1. 哈希表实现出现次数计算 O(n) 96 ms 29%
        # numMap = {}
        # for num in nums:
        #     if num not in numMap:
        #         numMap[num] = 1
        #     else:
        #         numMap[num] = numMap[num] + 1
        # for k, v in numMap.items():
        #     if v == 1:
        #         return k
        #
        # return None

        # 2. 数学 3 * 所有数 - 原来数列的和 = 2 * 一次数 56ms 83.11%
        # return (3 * sum(set(nums)) - sum(nums)) / 2

        # 3. 定义一种算法，
        # 让出现3次的数，进行运算后得到0，
        # 出现1次的最后得到本身
        # 这种算法不适合吾等榆木脑袋
        # https://leetcode-cn.com/problems/single-number-ii/solution/single-number-ii-mo-ni-san-jin-zhi-fa-by-jin407891/
        ones, twos = 0, 0
        for num in nums:
            ones = ones ^ num & ~twos
            twos = twos ^ num & ~ones
        return ones


if __name__ == '__main__':
    target = [0,1,0,1,0,1,99]
    print(Solution().singleNumber(target))
