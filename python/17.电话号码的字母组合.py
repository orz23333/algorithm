#
# @lc app=leetcode.cn id=17 lang=python3
#
# [17] 电话号码的字母组合
#

# @lc code=start
class Solution:
    # 回溯
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return list()
        
        phoneMap = {
            '2': ['a', 'b', 'c'],
            '3': ['d','e','f'],
            '4': ['g', 'h', 'i'],
            '5': ['j', 'k', 'l'],
            '6': ['m', 'n', 'o'],
            '7': ['p', 'q', 'r', 's'],
            '8': ['t', 'u', 'v'],
            '9': ['w', 'x', 'y', 'z'],
        }
        
        def backtrace(index):
            if index == len(digits):
                combinations.append("".join(combination))
            else:
                for ch in phoneMap[digits[index]]:
                    combination.append(ch)
                    backtrace(index + 1)
                    combination.pop()

        combination = list()
        combinations = list()
        backtrace(0)
        return combinations
# @lc code=end

