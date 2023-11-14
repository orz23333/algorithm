#
# @lc app=leetcode.cn id=78 lang=python3
#
# [78] 子集
#

# @lc code=start
class Solution:

    # 迭代法实现子集
    def subsets(self, nums: List[int]) -> List[List[int]]:
        combinations = list()
        combination = list()
        n = len(nums)
        for i in range(1 << n):
            combination.clear()
            for j in range(n):
                if i & (1 << j):
                    combination.append(nums[j])
            combinations.append(combination[:])
        return combinations

    # 递归法实现子集
    def subsets1(self, nums: List[int]) -> List[List[int]]:
        combination = list()
        combinations = list()
        length = len(nums)

        def backtrace(index):
            if index == length:
                combinations.append(combination[:])
            else:
                backtrace(index + 1)
                combination.append(nums[index])
                backtrace(index + 1)
                combination.pop()
                
        backtrace(0)
        return combinations

# @lc code=end

