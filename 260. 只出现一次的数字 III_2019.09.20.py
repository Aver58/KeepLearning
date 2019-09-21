""""
给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。

示例 :

输入: [1,2,1,3,2,5]
输出: [3,5]
注意：

结果输出的顺序并不重要，对于上面的例子， [5, 3] 也是正确答案。
你的算法应该具有线性时间复杂度。你能否仅使用常数空间复杂度来实现？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/single-number-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""


class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 1. 哈希表实现出现次数计算 O(n) 40 ms 99% 空间 5%
        # numMap = {}
        # for num in nums:
        #     if num not in numMap:
        #         numMap[num] = 1
        #     else:
        #         numMap[num] = numMap[num] + 1
        # resList = []
        # for k, times in numMap.items():
        #     if times == 1:
        #         resList.append(k)
        # return resList

        # 2. 暴力法 双层遍历 O(n ^ 2)

        # 3. 利用栈，没有就进入，有就pop，最后栈里就剩2个元素

        # 4. 第一名：位运算，脑子不够用了
        # xor_all = 0
        # for n in nums:
        #     xor_all ^= n
        #
        # xor_all &= -xor_all
        #
        # group1 = group2 = 0
        # for n in nums:
        #     if xor_all & n == xor_all:
        #         group1 ^= n
        #     else:
        #         group2 ^= n
        # return [group1, group2]

        # https://leetcode-cn.com/problems/single-number-iii/solution/zhi-chu-xian-yi-ci-de-shu-zi-iiixiang-jie-pai-xu-h/

if __name__ == '__main__':
    target = [1,2,1,3,2,5]
    print(Solution().singleNumber(target))
