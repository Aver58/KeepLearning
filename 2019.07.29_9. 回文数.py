""""
判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

示例 1:

输入: 121
输出: true
示例 2:

输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
示例 3:

输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。
进阶:

你能不将整数转为字符串来解决这个问题吗？

"""


class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        # 1.
        # numStr = str(x)
        # length = len(numStr)
        # for i in range(int(length/2)):
        #     if numStr[i] != numStr[length - i - 1]:
        #         return False
        # return True
        # 2. return str(x) == str(x)[::-1]
        # 进阶:你能不将整数转为字符串来解决这个问题吗？
        # 特殊情况：
        # 如上所述，当 x < 0 时，x 不是回文数。
        # 同样地，如果数字的最后一位是 0，为了使该数字为回文，
        # 则其第一位数字也应该是 0
        # 只有 0 满足这一属性
        if x < 0 or (x % 10 == 0 and x != 0):
            return False
        reverseNum = 0
        while x > reverseNum:
            reverseNum = reverseNum * 10 + x % 10
            x = int(x/10)
        return x == reverseNum or x == int(reverseNum / 10)


if __name__ == '__main__':
    nums1 = 4193914
    node = Solution().isPalindrome(nums1)
    print(node)
