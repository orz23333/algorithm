#
# @lc app=leetcode.cn id=27 lang=python3
#
# [27] 移除元素
#
from typing import List


# @lc code=start
class Solution:
    # 双指针优化，对向移动
    def removeElement(self, nums: List[int], val: int) -> int:
        n = len(nums)
        left = 0
        right = n - 1
        while left <= right:
            if nums[left] == val:
                nums[left] = nums[right]
                right -= 1
            else:
                left += 1
        return left

    # 双指针，同向移动
    def removeElement2(self, nums: List[int], val: int) -> int:
        left = 0
        for right, num in enumerate(nums):
            if num != val:
                nums[left] = num
                left += 1
        return left
# @lc code=end
