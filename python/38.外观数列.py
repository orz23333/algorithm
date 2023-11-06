#
# @lc app=leetcode.cn id=38 lang=python3
#
# [38] 外观数列
#


# @lc code=start
class Solution:
    # 官解
    def countAndSay(self, n: int) -> str:
        pre = '1'
        for i in range(1, n):
            start = 0
            post = 0
            cur = ''
            while post < len(pre):
                while post < len(pre) and pre[start] == pre[post]:
                    post += 1
                cur += str(post - start) + pre[start]
                start = post
            pre = cur
        return pre

    # 官解，直接枚举
    def countAndSay2(self, n: int) -> str:
        return '枚举打表'

    # 自写，可读性欠佳
    def countAndSay1(self, n: int) -> str:
        if n == 1:
            return '1'
        curIndex = 1
        curStr = '1'
        while curIndex < n:
            length = len(curStr)
            l = 0
            r = 0
            count = 0
            nextStr = ''
            while r < length:
                if curStr[l] == curStr[r]:
                    count += 1
                    r += 1
                else:
                    nextStr += str(count) + curStr[l]
                    count = 0
                    l = r
                if r == length:
                    nextStr += str(count) + curStr[l]
            curIndex += 1
            curStr = nextStr
        return curStr


# @lc code=end
