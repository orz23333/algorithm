#
# @lc app=leetcode.cn id=14 lang=python3
#
# [14] 最长公共前缀
#
from typing import List


# @lc code=start
class Solution:
    # 二分查找
    def longestCommonPrefix(self, strs: List[str]) -> str:

        def isCommonPrefix(length):
            baseStr = strs[0][:length]
            count = len(strs)
            return all(baseStr == strs[i][:length] for i in range(1, count))

        if not strs:
            return ''

        minLength = min(len(s) for s in strs)
        low = 0
        high = minLength
        while low < high:
            mid = (high - low + 1) // 2 + low
            if isCommonPrefix(mid):
                low = mid
            else:
                high = mid - 1
        return strs[0][:low]

    # 分治
    def longestCommonPrefix3(self, strs: List[str]) -> str:

        def lcp(left, right):
            if left == right:
                return strs[left]
            mid = (left + right) // 2
            lcpLeft, lcpRight = lcp(left, mid), lcp(mid + 1, right)
            minLength = min(len(lcpLeft), len(lcpRight))
            for i in range(minLength):
                if lcpLeft[i] != lcpRight[i]:
                    return lcpLeft[:i]
            return lcpLeft[:minLength]

        return '' if not strs else lcp(0, len(strs) - 1)

    # 横向遍历
    def longestCommonPrefix2(self, strs: List[str]) -> str:

        def lcp(s1: str, s2: str) -> str:
            length = min(len(s1), len(s2))
            index = 0
            while index < length and s1[index] == s2[index]:
                index += 1
            return s1[:index]

        if not strs:
            return ''

        count = len(strs)
        prefix = strs[0]
        for i in range(count):
            prefix = lcp(prefix, strs[i])
            if not prefix:
                break
        return prefix

    # 排序找出最短字符串，然后逐个匹配最长公共前缀
    def longestCommonPrefix1(self, strs: List[str]) -> str:
        if not strs:
            return ''
        copyStrs = sorted(strs, key=len)
        shorted = copyStrs[0]
        n = len(copyStrs)
        m = len(shorted)
        ret = ''
        for i in range(m + 1):
            for s in copyStrs:
                if shorted[:i] != s[:i]:
                    return ret
            ret = shorted[:i]
        return ret


Solution().longestCommonPrefix(['a'])
# @lc code=end
