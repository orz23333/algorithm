#
# @lc app=leetcode.cn id=242 lang=python3
#
# [242] 有效的字母异位词
#


# @lc code=start
class Solution:

    def isAnagram(self, s: str, t: str) -> bool:
        bitmap = [0] * 26
        for i, ch in enumerate(s):
            bitmap[ord(ch) - ord('a')] += 1

        for i, ch in enumerate(t):
            bitmap[ord(ch) - ord('a')] -= 1

        sum = 0
        for i in bitmap:
            sum += abs(i)

        return True if sum == 0 else False


# @lc code=end
