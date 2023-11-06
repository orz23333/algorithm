#
# @lc app=leetcode.cn id=198 lang=python3
#
# [198] 打家劫舍
#

# @lc code=start
class Solution:
    # 一维数组，如果追求空间效率，还可以用滚动数组
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n < 2:
            return nums[0]
        ans = [0] * n
        ans[0] = nums[0]
        ans[1] = max(ans[0], nums[1])
        for i in range(2, n):
            ans[i] = max(ans[i - 2] + nums[i], ans[i - 1])
        return ans[n - 1]

    # 二维数组
    def rob1(self, nums: List[int]) -> int:
        n = len(nums)
        ans = [[0, 0] for _ in range(n)]
        ans[0][0] = 0
        ans[0][1] = nums[0]
        for i in range(1, n):
            ans[i][0] = max(ans[i - 1][0], ans[i - 1][1])
            ans[i][1] = ans[i - 1][0] + nums[i]
        return max(ans[n - 1][0], ans[n - 1][1])
# @lc code=end
