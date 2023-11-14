#
# @lc app=leetcode.cn id=46 lang=python3
#
# [46] 全排列
#

# @lc code=start
class Solution:
    # 回溯：使用袁原数组，结果乱序
    def permute(self, nums: List[int]) -> List[List[int]]:
        ans = list()
        n = len(nums)

        def backtrace(index):
            if index == n:
                ans.append(nums[:])
            else:
                for i in range(index, n):
                    nums[index], nums[i] = nums[i], nums[index]
                    backtrace(index + 1)
                    nums[index], nums[i] = nums[i], nums[index]
        
        backtrace(0)
        return ans

    # 回溯：维护一个标记数组
    def permute1(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        combination = list()
        combinations = list()
        used = [0] * n

        def backtrace(index):
            
            if index == n:
                combinations.append(combination.copy())
            else:
                for i, num in enumerate(nums):
                    if not used[i]:
                        combination.append(num)
                        used[i] = 1
                        backtrace(index + 1)
                        combination.pop()
                        used[i] = 0
        
        backtrace(0)
        return combinations
    
# @lc code=end

