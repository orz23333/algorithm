#
# @lc app=leetcode.cn id=121 lang=python3
#
# [121] 买卖股票的最佳时机
#

# @lc code=start
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minPrice = float('inf')
        profit = 0
        n = len(prices)
        for i in range(n):
            minPrice = min(prices[i], minPrice)
            profit = max(prices[i] - minPrice, profit)
        return profit

    # 丑陋解法，生搬硬套动态规划
    def maxProfit1(self, prices: List[int]) -> int:
        n = len(prices)
        ans = [0] * n
        minPrice = prices[0]
        for i in range(1, n):
            minPrice = min(prices[i], minPrice)
            ans[i] = max(ans[i - 1], prices[i] - minPrice)
        return ans[n - 1]

# @lc code=end

