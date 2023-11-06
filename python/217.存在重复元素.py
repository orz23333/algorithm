#
# @lc app=leetcode.cn id=217 lang=python3
#
# [217] 存在重复元素
#

# @lc code=start
class Solution:
    # 排序，再比较
    def containsDuplicate(self, nums: List[int]) -> bool:
        nums.sort()
        n = len(nums)
        for i in range(n - 1):
            if nums[i] == nums[i + 1]:
                return True
        return False

    # hash表
    def containsDuplicate2(self, nums: List[int]) -> bool:
        hashset = set()
        for i, num in enumerate(nums):
            if num in hashset:
                return True
            hashset.add(num)
        return False
# @lc code=end

