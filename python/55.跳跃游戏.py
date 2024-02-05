#
# @lc app=leetcode.cn id=55 lang=python3
#
# [55] 跳跃游戏
#


# @lc code=start
class Solution:

    def canJump(self, nums: List[int]) -> bool:
        distince = 0
        n = len(nums)
        for i, num in enumerate(nums):
            if distince >= i:
                distince = max(distince, i + num)
                if distince >= n - 1:
                    return True
        return False


# @lc code=end
