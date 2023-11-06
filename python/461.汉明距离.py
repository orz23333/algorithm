#
# @lc app=leetcode.cn id=461 lang=python3
#
# [461] 汉明距离
#

# @lc code=start
class Solution:
    # 内置函数
    def hammingDistance(self, x: int, y: int) -> int:
        return bin(x ^ y).count('1')

    # Brian Kernighan 算法
    def hammingDistance1(self, x: int, y: int) -> int:
        distance = x ^ y
        count = 0
        while distance:
            count += 1
            distance &= distance - 1
        return count
# @lc code=end

