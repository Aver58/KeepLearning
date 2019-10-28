""""
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

输入: "A man, a plan, a canal: Panama"
输出: true
示例 2:

输入: "race a car"
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-palindrome
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""

import re


class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        # 1. 做个需要的列表，然后双指针遍历52 ms 59.54%
        if s == "":
            return True
        # _list = [x.lower() for x in s if x.isalpha() or x.isdigit()]
        # left = 0
        # right = len(_list) - 1
        # while left < right:
        #     if _list[left] != _list[right]:
        #         return False
        #     left += 1
        #     right -= 1
        # return True

        # 2. 第一名 32 ms  97.34%
        s = re.sub(r"[^A-Za-z0-9]", "", s.lower())
        return s == s[::-1]


if __name__ == '__main__':
    target = "race a car"
    print(Solution().isPalindrome(target))
