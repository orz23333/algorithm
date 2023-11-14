#
# @lc app=leetcode.cn id=22 lang=python3
#
# [22] 括号生成
#


# @lc code=start
class Solution:
    # 按括号序列的长度递归：看不懂
    @lru_cache(None)
    def generateParenthesis(self, n: int) -> List[str]:
        if n == 0:
            return ['']
        ans = []
        for c in range(n):
            for left in self.generateParenthesis(c):
                for right in self.generateParenthesis(n - c - 1):
                    ans.append('({}){}'.format(left, right))            
        return ans

    # 回溯：官解
    def generateParenthesis2(self, n: int) -> List[str]:
        ans = list()
        def backtrace(combination, left, right):
            if len(combination) == 2 * n:
                ans.append(''.join(combination))
                return
            if left < n:
                combination.append('(')
                backtrace(combination, left + 1, right)
                combination.pop()
            if right < left:
                combination.append(')')
                backtrace(combination, left, right + 1)
                combination.pop()
        backtrace([], 0, 0)
        return ans

    # 回溯：自解
    def generateParenthesis1(self, n: int) -> List[str]:
        counts = {
            '(': 0,
            ')': 0,
        }

        def backtrace(index):
            if index == n * 2:
                combinations.append(''.join(combination))
            else:
                if counts['('] < n:
                    counts['('] += 1
                    combination.append('(')
                    backtrace(index + 1)
                    combination.pop()
                    counts['('] -= 1
                if counts[')'] < counts['(']:
                    counts[')'] += 1
                    combination.append(')')
                    backtrace(index + 1)
                    combination.pop()
                    counts[')'] -= 1

        combination = list()
        combinations = list()
        backtrace(0)
        return combinations


# @lc code=end
