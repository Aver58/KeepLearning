""""
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:

输入: [2,2,1]
输出: 1
示例 2:

输入: [4,1,2,1,2]
输出: 4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/single-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""


class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 1. 哈希表实现出现次数计算 O(n) 100 ms 47.78%
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

        # 1. 1 优化版
        # 上面把所有出现的都记录下来到哈希表，但是最后要找出那个出现次数为1的时候，需要遍历哈希表
        # 其实，我们可以第一次出现的时候，记录哈希表，第二次出现，清除对应哈希表，
        # 那么最后留下来的就是出现一次的数
        # numMap = {}
        # for num in nums:
        #     if num in numMap:
        #         numMap.pop(num)
        #     else:
        #         numMap[num] = 1
        # return numMap.popitem()[0]

        # 3. 位运算,这个也太酷了吧，
        # 时间复杂度： O(n)空间复杂度：O(1)
        # 如果出现两次，按位异或运算，得到0，
        # 只有出现1次的才能留下来
        # a = 0
        # for i in nums:
        #     a ^= i
        # return a

        # 第一名 也是位运算
        # return reduce(int.__xor__, nums)

        # 方法 4：数学
        # sum 会调用 next 将 nums 中的元素遍历一遍。
        # print(set(nums)) #{1, 2, 4, 5}
        # 把所有不重复的数 * 2 减去原来的数的和，得到的就是只有一个的数
        # return 2 * sum(set(nums)) - sum(nums)


if __name__ == '__main__':
    target = [4,1,2,1,2,4,5]
    print(Solution().singleNumber(target))
