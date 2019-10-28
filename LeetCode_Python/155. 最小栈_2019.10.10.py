""""
设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。

push(x) -- 将元素 x 推入栈中。
pop() -- 删除栈顶的元素。
top() -- 获取栈顶元素。
getMin() -- 检索栈中的最小元素。
示例:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/min-stack
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""

import sys


class MinStack(object):
    # 1. 用一个辅助栈 同步 52 ms 96%
    # def __init__(self):
    #     """
    #     initialize your data structure here.
    #     """
    #     self._stack = []
    #     self._minStack = []
    #
    # def push(self, x):
    #     """
    #     :type x: int
    #     :rtype: None
    #     """
    #     if len(self._minStack) < 1 or x < self._minStack[-1]:
    #         self._minStack.append(x)
    #     else:
    #         self._minStack.append(self._minStack[-1])
    #     self._stack.append(x)
    #
    # def pop(self):
    #     """
    #     :rtype: None
    #     """
    #     if self._stack:
    #         self._stack.pop()
    #         return self._minStack.pop()
    #
    # def top(self):
    #     """
    #     :rtype: int
    #     """
    #     if self._stack:
    #         return self._stack[-1]
    #
    # def getMin(self):
    #     """
    #     :rtype: int
    #     """
    #     if self._minStack:
    #         return self._minStack[-1]

    # 2. 不要辅助栈，每次入栈入栈2个，一个是当前值，一个是当前最小值 56ms 92%
    def __init__(self):
        self._min = sys.maxsize
        self._data = []

    def push(self, x):
        self._data.append(x)
        if x < self._min:
            self._min = x
        self._data.append(self._min)

    def pop(self):
        minValue = self._data.pop()
        popValue = self._data.pop()
        if len(self._data) > 0:
            self._min = self._data[-1]
        else:
            self._min = sys.maxsize
        return popValue

    def top(self):
        if self._data:
            return self._data[-2]

    def getMin(self):
        if self._data:
            return self._min


if __name__ == '__main__':
    obj = MinStack()
    obj.push(-2)
    obj.push(0)
    obj.push(-3)
    param_4 = obj.getMin()
    obj.pop()
    param_3 = obj.top()
    print(param_4)
    print(param_3)
