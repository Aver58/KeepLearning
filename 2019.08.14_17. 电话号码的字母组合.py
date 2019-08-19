""""
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。 2（abc）、3（def）、4（ghi）。。。7（pqrs）、8(tuv)、9（wxyz）

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。



示例:

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
说明:
尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。

"""


class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        result = []
        if digits is None or len(digits) == 0:
            return result
        KEY = {'2': ['a', 'b', 'c'],
               '3': ['d', 'e', 'f'],
               '4': ['g', 'h', 'i'],
               '5': ['j', 'k', 'l'],
               '6': ['m', 'n', 'o'],
               '7': ['p', 'q', 'r', 's'],
               '8': ['t', 'u', 'v'],
               '9': ['w', 'x', 'y', 'z']}
        # 用递归去解
        def recursive(str,digit):
            if len(digit) <= 0:
                result.append(str)
            else:
                for letter in KEY[digit[0]]:
                    recursive(str + letter, digit[1:])
        recursive("", digits)
        return result


if __name__ == '__main__':
    digits = "23"
    node = Solution().letterCombinations(digits)
    print(node)
