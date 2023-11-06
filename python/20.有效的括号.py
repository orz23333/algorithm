#
# @lc app=leetcode.cn id=20 lang=python3
#
# [20] 有效的括号
#


# @lc code=start
class Solution:
    def isValid(self, s: str) -> bool:
        if len(s) % 2 == 1:
            return False
        pairs = {
            ']' : '[',
            '}' : '{',
            ')' : '(',
        }
        stack = list()
        for ch in s:
            if ch in pairs:
                if not stack or stack[-1] != pairs[ch]:
                    return False
                stack.pop()
            else:
                stack.append(ch)
        return not stack

    # 丑陋的代码
    def isValid1(self, s: str) -> bool:
        stack = list()
        for _, ch in enumerate(s):
            if ch == '(' or ch == '[' or ch == '{':
                stack.append(ch)
            elif ch == ')':
                if not stack:
                    return False
                out = stack.pop()
                if out != '(':
                    return False
            elif ch == '}':
                if not stack:
                    return False
                out = stack.pop()
                if out != '{':
                    return False
            elif ch == ']':
                if not stack:
                    return False
                out = stack.pop()
                if out != '[':
                    return False
            else:
                return False
        if stack:
            return False
        return True


# Solution().isValid('()')

# @lc code=end
