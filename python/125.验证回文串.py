#
# @lc app=leetcode.cn id=125 lang=python3
#
# [125] 验证回文串
#


# @lc code=start
class Solution:
    # 原地比较
    def isPalindrome(self, s: str) -> bool:
        n = len(s)
        l = 0
        r = n - 1
        while l < r:
            while l < r and not s[l].isalnum():
                l += 1
            while l < r and not s[r].isalnum():
                r -= 1
            if l < r and s[l].lower() != s[r].lower():
                return False
            l += 1
            r -= 1
        return True

    # 筛选，判断
    def isPalindrome1(self, s: str) -> bool:
        tran_str = ''
        for i, ch in enumerate(s):
            if ch.isalnum():
                tran_str += ch.lower()
        n = len(tran_str)
        l = 0
        r = n - 1
        while l < r:
            if tran_str[l] != tran_str[r]:
                return False
            l += 1
            r -= 1
        return True


# @lc code=end
