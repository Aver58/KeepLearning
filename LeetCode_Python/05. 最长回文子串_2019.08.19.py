""""
5. 最长回文子串
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-palindromic-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""


class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        if s is None or s == '':
            return s
        # 1. 暴力解法：时间复杂度：O(n^3)空间复杂度：O(1)
        # longest = ''
        # for i in range(len(s)):
        #     for j in range(i + 1, len(s)):
        #         str = s[i:j]
        #         if str == str[::-1] and len(str) > len(longest):
        #             longest = str
        # return longest

        # 2. 动态规划
        # 结合53题 把这题拆成最长子串和回文两个问题
        sum = nums[0]



if __name__ == '__main__':
    nums1 = 'babad'
    # nums1 = 'abcdef'
    node = Solution().longestPalindrome(nums1)
    print(node)
    # print(type(nums1))
