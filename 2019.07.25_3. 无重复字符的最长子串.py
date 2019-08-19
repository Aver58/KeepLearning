""""
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
"""


class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s:
            return 0
        st = {}
        i, ans = 0, 0
        # 滑动窗口，如果字符重复，将窗口向右移动一格就能不重复了！！！
        # https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/hua-jie-suan-fa-3-wu-zhong-fu-zi-fu-de-zui-chang-z/
        for j in range(len(s)):
            if s[j] in st:
                i = max(st[s[j]] + 1, i)
            ans = max(ans, j - i + 1)
            st[s[j]] = j
        return ans


if __name__ == '__main__':
    s = "dvdf"
    node = Solution().lengthOfLongestSubstring(s)
    print(node)
