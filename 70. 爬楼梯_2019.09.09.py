""""
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。

示例 1：

输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶
示例 2：

输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 阶 + 1 阶 + 1 阶
2.  1 阶 + 2 阶
3.  2 阶 + 1 阶

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/climbing-stairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""


class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        # 1. 斐波那契数 28 ms 29.70%
        # if n == 0:
        #     return 0
        # elif n == 1:
        #     return 1
        # else:
        #     first = 1
        #     second = 2
        #     for i in range(2, n):
        #         third = first + second
        #         first = second
        #         second = third
        #     return second

        # 2. 第一名 20 ms 77.84%
        # if n == 1:
        #     return 1
        # if n == 2:
        #     return 2
        #
        # f=[]
        # f.append(1)
        # f.append(2)
        # for i in range(2, n):
        #     f.append(f[i-1]+f[i-2])
        # return f[-1]

        # 3.

if __name__ == '__main__':
    target = 5
    print(Solution().climbStairs(target))
