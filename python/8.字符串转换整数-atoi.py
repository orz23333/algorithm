#
# @lc app=leetcode.cn id=8 lang=python3
#
# [8] 字符串转换整数 (atoi)
#
# @lc code=start
INT_MAX = (2**31 - 1)
INT_MIN = (-2**31)


class Automaton:
    # 状态机
    def __init__(self) -> None:
        self.ans = 0
        self.sign = 1
        self.state = 'start'
        self.table = {
            'start': ['start', 'signed', 'in_number', 'end'],
            'signed': ['end', 'end', 'in_number', 'end'],
            'in_number': ['end', 'end', 'in_number', 'end'],
            'end': ['end', 'end', 'end', 'end']
        }

    def get_col(self, s: str) -> int:
        if s.isspace():
            return 0
        elif s == '+' or s == '-':
            return 1
        elif s.isdigit():
            return 2
        else:
            return 3

    def get(self, s: str):
        self.state = self.table[self.state][self.get_col(s)]
        if self.state == 'signed':
            self.sign = -1 if s == '-' else 1
        elif self.state == 'in_number':
            self.ans = self.ans * 10 + int(s)
            self.ans = min(self.ans, -INT_MIN) if self.sign == -1 else min(
                self.ans, INT_MAX)


class Solution:
    # 状态机
    def myAtoi(self, s: str) -> int:
        automaton = Automaton()
        for ch in s:
            automaton.get(ch)
        return automaton.ans * automaton.sign

    # 非状态机
    def myAtoi1(self, s: str) -> int:
        s = s.lstrip()
        isNeg = False
        if not s:
            return 0
        elif (s[0] == '+' or s[0] == '-'):
            isNeg = True if s[0] == '-' else False
            s = s[1:]
        rec = 0

        for i, ch in enumerate(s):
            if ch.isnumeric():
                rec = rec * 10 + ord(ch) - ord('0')
            else:
                break
        rec = rec if not isNeg else -rec
        if rec < INT_MIN:
            return INT_MIN
        elif rec > INT_MAX:
            return INT_MAX
        return rec


print(Solution().myAtoi("   -42"))
# @lc code=end
