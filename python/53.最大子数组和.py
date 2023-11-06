#
# @lc app=leetcode.cn id=53 lang=python3
#
# [53] 最大子数组和
#

# @lc code=start
class Solution:

    def maxSubArray(self, nums: List[int]) -> int:
        n = len(nums)
        ans = [0] * n
        ans[0] = nums[0]
        ret = ans[0]
        for i in range(1, n):
            ans[i] = max(ans[i - 1] + nums[i], nums[i])
            ret = max(ret, ans[i])
        return ret
# @lc code=end
