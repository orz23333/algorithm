#
# @lc app=leetcode.cn id=28 lang=python3
#
# [28] 找出字符串中第一个匹配项的下标
#


# @lc code=start
class Solution:
    # KMP解法
    def strStr(self, haystack: str, needle: str) -> int:

    # 暴力遍历，python写法
    def strStr2(self, haystack: str, needle: str) -> int:
        for i in range(0, len(haystack) - len(needle) + 1):
            if haystack[i:i + len(needle)] == needle:
                return i
        return -1

    # 暴力遍历
    def strStr1(self, haystack: str, needle: str) -> int:
        for i, _ in enumerate(haystack):
            isFind = self.dfs(haystack[i:], needle)
            if isFind:
                return i
        return -1

    def dfs(self, s1: str, s2: str) -> bool:
        n1 = len(s1)
        n2 = len(s2)
        if n2 > n1:
            return False
        if s1 and not s2:
            return True
        elif not s1 and s2:
            return False
        elif not s1 and not s2:
            return True
        elif s1[0] != s2[0]:
            return False
        else:
            return self.dfs(s1[1:], s2[1:])


# print(Solution().strStr("leetcode", "leeto"))
# @lc code=end
