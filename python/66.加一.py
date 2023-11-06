#
# @lc app=leetcode.cn id=66 lang=python3
#
# [66] 加一
#
from typing import List


# @lc code=start
class Solution:
    # 算9
    def plusOne(self, digits: List[int]) -> List[int]:
        n = len(digits)
        for i in range(n - 1, -1, -1):
            if digits[i] != 9:
                digits[i] += 1
                for j in range(i + 1, n):
                    digits[j] = 0
                return digits
        return [1] + [0] * n

    # 取模运算
    def plusOne1(self, digits: List[int]) -> List[int]:
        index = len(digits) - 1
        digits[index] += 1
        carry = 0
        while index >= 0:
            total = (digits[index] + carry)
            digits[index] = total % 10
            carry = total // 10
            index -= 1
        if carry > 0:
            ret = [0] * (len(digits) + 1)
            ret[0] = carry
            ret[1:] = digits
            return ret
        return digits


# @lc code=end

