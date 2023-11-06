#
# @lc app=leetcode.cn id=70 lang=python3
#
# [70] 爬楼梯
#

# @lc code=start
class Solution:
    # 矩阵快速幂、通项公式算法略

    # 滚动数组写法2
    def climbStairs(self, n: int) -> int:
        step1 = 0
        step2 = 0
        cur = 1
        for i in range(1, n + 1):
            step1 = step2
            step2 = cur
            cur = step1 + step2
        return cur

    # 滚动数组写法1
    def climbStairs3(self, n: int) -> int:
        if n < 2:
            return 1
        pre1 = 1
        pre2 = 1
        cur = 0
        for i in range(2, n + 1):
            cur = pre1 + pre2
            pre1 = pre2
            pre2 = cur
        return cur

    # 迭代，借用数组
    def climbStairs2(self, n: int) -> int:
        if n < 2:
            return 1
        ans = [0] * (n + 1)
        ans[0] = 1
        ans[1] = 1
        for i in range(2, n + 1):
            ans[i] = ans[i - 1] + ans[i - 2]
        return ans[n]

    #  递归：超时
    def climbStairs1(self, n: int) -> int:
        if n < 2:
            return 1
        return self.climbStairs(n - 1) + self.climbStairs(n - 2)
# @lc code=end

