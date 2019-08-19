""""
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例 1:

输入: 123
输出: 321
 示例 2:

输入: -123
输出: -321
示例 3:

输入: 120
输出: 21
注意:

假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。
"""


class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        """        
        result = 0
        source = abs(x)
        boundary = x > 0 and (1 << 31) - 1 or 1 << 31
        while source != 0:
            result = result * 10 + source % 10
            if result > boundary:
                return 0
            source //= 10
        return x > 0 and result or -result
        """
        # ::双冒号，从[1:10:1]从1到10，每次1步
        s = str(x)[::-1].rstrip('-')
        if int(s) < 1 << 31:
            return x >= 0 and int(s) or -int(s)
        return 0


if __name__ == '__main__':
    nums1 = -123
    node = Solution().reverse(nums1)
    print(node)
