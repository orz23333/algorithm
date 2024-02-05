#
# @lc app=leetcode.cn id=62 lang=python3
#
# [62] 不同路径
#
from math import *

# @lc code=start
class Solution:
    # 数学排列组合：api
    def uniquePaths(self, m: int, n: int) -> int:
        # return comb(m + n - 2, m - 1)
        return int(perm(m + n - 2, m - 1) / factorial(m - 1))

    # 数学排列组合
    def uniquePaths2(self, m: int, n: int) -> int:
        ans = 1
        i = n
        for j in range(1, m):
            ans = ans * i / j
            i += 1
            j += 1
        return int(ans)

    # 动态规划
    def uniquePaths1(self, m: int, n: int) -> int:
        f = [[1] * n] + [[1] + [0] * (n - 1) for _ in range(m - 1)]
        for i in range(1, m):
            for j in range(1, n):
                f[i][j] = f[i - 1][j] + f[i][j - 1]
        return f[m - 1][n - 1]
# @lc code=end
