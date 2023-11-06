#
# @lc app=leetcode.cn id=189 lang=python3
#
# [189] 轮转数组
#
from typing import List
import math

# @lc code=start
class Solution:
    # 环形替换， 用到了数学知识
    def rotate(self, nums: List[int], k: int) -> None:
        n = len(nums)
        k = k % n
        gcd = math.gcd(n, k)
        for start in range(0, gcd):
            cur = start
            pre = nums[start]
            while True:
                next = (cur + k) % n
                nums[next], pre = pre, nums[next]
                cur = next
                if cur == start:
                    break

    # 数组翻转
    def rotate3(self, nums: List[int], k: int) -> None:
        n = len(nums)
        offset = k % n
        self.swap(nums, 0, n - 1)
        self.swap(nums, 0, offset - 1)
        self.swap(nums, offset, n - 1)

    # 复制数组，然后赋值(通用)
    def rotate2(self, nums: List[int], k: int) -> None:
        n = len(nums)
        tempArr = [0] * n
        for i, _ in enumerate(nums):
            tempArr[(i + k) % n] = nums[i]
        nums[:] = tempArr[:]

    # 复制数组，然后赋值(python 语法)
    def rotate1(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        offset = k % len(nums)
        if not offset:
            return
        copy = nums[:]
        nums[:offset] = copy[-offset:]
        nums[offset:] = copy[:-offset]

    def swap(self, nums: List[int], left: int, right: int) -> None:
        while left < right:
            temp = nums[left]
            nums[left] = nums[right]
            nums[right] = temp
            left += 1
            right -= 1

# Solution().rotate([1], 0)
# @lc code=end

