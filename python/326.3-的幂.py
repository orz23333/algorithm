#
# @lc app=leetcode.cn id=326 lang=python3
#
# [326] 3 的幂
#

# @lc code=start
class Solution:
    # 特殊值
    def isPowerOfThree(self, n: int) -> bool:
        return n > 0 and 1162261467 % n == 0

    # 枚举
    def isPowerOfThree1(self, n: int) -> bool:
        while n and n % 3 == 0:
            n //= 3
        return n == 1
# @lc code=end
