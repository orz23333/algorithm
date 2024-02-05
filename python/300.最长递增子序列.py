#
# @lc app=leetcode.cn id=300 lang=python3
#
# [300] 最长递增子序列
#


# @lc code=start
class Solution:
    # 贪心 + 二分查找
    def lengthOfLIS(self, nums: List[int]) -> int:
        dp = []
        for num in nums:
            if not dp or num > dp[-1]:
                dp.append(num)
            else:
                l = 0
                r = len(dp) - 1
                loc = r
                while l <= r:
                    mid = (l + r) // 2
                    if dp[mid] >= num:
                        loc = mid
                        r = mid - 1
                    else:
                        l = mid + 1
                dp[loc] = num
        return len(dp)

    # 动态规划
    def lengthOfLIS1(self, nums: List[int]) -> int:
        dp = []
        n = len(nums)
        for i in range(n):
            dp.append(1)
            for j in range(i):
                if nums[j] < nums[i]:
                    dp[i] = max(dp[i], dp[j] + 1)
        return max(dp)


# @lc code=end
