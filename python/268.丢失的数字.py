#
# @lc app=leetcode.cn id=268 lang=python3
#
# [268] 丢失的数字
#

# @lc code=start
class Solution:
    # 异或
    def missingNumber(self, nums: List[int]) -> int:
        xor = 0
        n = len(nums)
        for i in nums:
            xor ^= i
        for i in range(n + 1):
            xor ^= i
        return xor

    # 高斯求和
    def missingNumber2(self, nums: List[int]) -> int:
        curSum = sum(nums)
        baseSum = (len(nums) + 1) * len(nums) / 2
        return int(baseSum - curSum)

    # 朴素算法
    def missingNumber1(self, nums: List[int]) -> int:
        for i in range(len(nums) + 1):
            if i not in nums:
                return i
        return -1
# @lc code=end

