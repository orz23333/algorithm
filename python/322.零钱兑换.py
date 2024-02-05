#
# @lc app=leetcode.cn id=322 lang=python3
#
# [322] 零钱兑换
#
import functools

# @lc code=start
class Solution:
    # 记忆化搜索
    def coinChange(self, coins: List[int], amount: int) -> int:
        @functools.lru_cache(amount)
        def dfs(rem):
            if rem < 0:
                return -1
            if rem == 0:
                return 0
            mini = int(1e9)
            for coin in coins:
                num = dfs(rem - coin)
                if 0 <= num < mini:
                    mini = num + 1
            return mini if mini < int(1e9) else -1
        
        return dfs(amount)

    # 动态规划
    def coinChange2(self, coins: List[int], amount: int) -> int:
        ans = [float('inf')] * (amount + 1)
        ans[0] = 0
        for coin in coins:
            for i in range(coin, amount + 1):
                ans[i] = min(ans[i], ans[i - coin] + 1)
        return ans[amount] if ans[amount] != float('inf') else -1

# @lc code=end

