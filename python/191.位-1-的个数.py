#
# @lc app=leetcode.cn id=191 lang=python3
#
# [191] 位1的个数
#

# @lc code=start
class Solution:
    # 位运算优化
    def hammingWeight(self, n: int) -> int:
        count = 0
        while n:
            count += 1
            n &= n - 1
        return count

    # 循环检查二进制位
    def hammingWeight1(self, n: int) -> int:
        ret = sum([1 for i in range(32) if 1 << i & n])
        return ret
        
# @lc code=end

