""""
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:

输入: "()"
输出: true
示例 2:

输入: "()[]{}"
输出: true
示例 3:

输入: "(]"
输出: false
示例 4:

输入: "([)]"
输出: false
示例 5:

输入: "{[]}"
输出: true

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""

ValidMap = {
    '(': ')',
    '[': ']',
    '{': '}',
}


class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        if s is None:
            return True
        # 1. 使用额外的栈处理
        stack = []
        # 如果遇到开括号，我们只需将其推到栈上即可。这意味着我们将稍后处理它，
        # 如果我们遇到一个闭括号，那么我们检查栈顶的元素。
        # 如果栈顶的元素是一个 相同类型的 左括号，那么我们将它从栈中弹出并继续处理。
        # 否则，这意味着表达式无效。
        for char in s:
            if char in ValidMap:
                # 左括号
                stack.append(char)
            else:
                # 右括号
                if len(stack) > 0:
                    s = stack.pop()
                    if ValidMap[s] != char:
                        return False
                else:
                    return False
        return len(stack) <= 0


if __name__ == '__main__':
    s = '([)]"'
    node = Solution().isValid(s)
    print(node)
