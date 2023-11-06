#
# @lc app=leetcode.cn id=1 lang=python3
#
# [1] 两数之和
#

# @lc code=start
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashMap = dict()
        for i, num in enumerate(nums):
            res = target - num
            if res in hashMap:
                return [i, hashMap.get(res)]
            else:
                hashMap[num] = i
        return None
# @lc code=end

