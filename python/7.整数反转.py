#
# @lc app=leetcode.cn id=7 lang=python3
#
# [7] 整数反转
#


# @lc code=start
class Solution:
    # 非常恶心的负数问题
    def reverse(self, x: int) -> int:
        INT_MAX = (2**31 - 1) // 10
        INT_MIN = (-2**31) // 10 + 1

        rec = 0
        digit = 0
        while x != 0:
            if rec < INT_MIN or rec > INT_MAX:
                return 0
            digit = x % 10
            if x < 0 and digit > 0:
                digit -= 10
            x = (x - digit) // 10
            rec = rec * 10 + digit
        return rec

    # x 取反
    def reverse1(self, x: int) -> int:
        INT_MAX = 2**31 - 1
        INT_MIN = -2**31
        rec = 0
        digit = 0
        is_negative = False
        if x < 0:
            is_negative = True
            x = -x
        while x != 0:
            if rec < INT_MIN // 10 + 1 or rec > INT_MAX // 10:
                return 0
            digit = x % 10
            if x < 0 and digit > 0:
                digit -= 10
            x //= 10
            rec = rec * 10 + digit
        return -rec if is_negative else rec

# @lc code=end
