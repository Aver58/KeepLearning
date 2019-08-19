""""
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。

"""


class Solution(object):
    def longestCommonPrefix(self, strList):
        """
        :type strList: List[str]
        :rtype: str
        """
        if not strList or len(strList) <= 0:
            return ""
        firstStr = strList[0]
        for i in range(len(firstStr)):
            tempChar = firstStr[i]
            for str in strList:
                if len(str) == i or str[i] != tempChar:
                    return firstStr[0:i]
        return firstStr


if __name__ == '__main__':
    nums1 = ["aa","a"]
    node = Solution().longestCommonPrefix(nums1)
    print(node)
