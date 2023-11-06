#
# @lc app=leetcode.cn id=136 lang=python3
#
# [136] 只出现一次的数字
#

# @lc code=start
class Solution:
    # 异或操作，一次遍历
    def singleNumber(self, nums: List[int]) -> int:
        ret = 0
        for _, num in enumerate(nums):
            ret ^= num
        return ret
# @lc code=end

