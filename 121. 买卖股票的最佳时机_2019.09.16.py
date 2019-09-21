""""
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。

注意你不能在买入股票前卖出股票。

示例 1:

输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
示例 2:

输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""


class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        # 1. 一次遍历
        # 时间复杂度：O(n) 空间复杂度为 O(1)
        # 先找到买入点(最小值，索引)
        # 找到卖出点(最大值且索引比最小值大)
        if prices is None or len(prices) <= 0:
            return 0

        minVal = prices[0]
        maxProfit = 0
        for i in range(len(prices)):
            if prices[i] < minVal:
                # 更新最小值
                minVal = prices[i]
            elif prices[i] - minVal > maxProfit:
                # 更新最大利润
                maxProfit = prices[i] - minVal
        return maxProfit


if __name__ == '__main__':
    target = [10,2,9,1,2,1,3,1]
    print(Solution().maxProfit(target))
