#
# @lc app=leetcode.cn id=384 lang=python3
#
# [384] 打乱数组
#


# @lc code=start
class Solution:

    # Fisher-Yates 洗牌算法
    def __init__(self, nums: List[int]):
        self.origin = nums.copy()
        self.nums = nums

    def reset(self) -> List[int]:
        self.nums = self.origin.copy()
        return self.nums

    def shuffle(self) -> List[int]:
        n = len(self.nums)
        for i in range(n):
            index = random.randrange(i, n)
            self.nums[index], self.nums[i] = self.nums[i], self.nums[index]
        return self.nums

'''
    # 暴力法
    def __init__(self, nums: List[int]):
        self.origin = nums.copy()
        self.nums = nums

    def reset(self) -> List[int]:
        self.nums = self.origin.copy()
        return self.nums

    def shuffle(self) -> List[int]:
        n = len(self.origin)
        shuffled = [0] * n
        for i in range(n):
            index = random.randrange(len(self.nums))
            shuffled[i] = self.nums.pop(index)
        self.nums = shuffled
        return self.nums

    # 调用api
    def __init__(self, nums: List[int]):
        self.ori = nums.copy()
        self.input = nums.copy()

    def reset(self) -> List[int]:
        return self.ori

    def shuffle(self) -> List[int]:
        random.shuffle(self.input)
        return self.input
'''
# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()
# @lc code=end
