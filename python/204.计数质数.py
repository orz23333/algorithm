#
# @lc app=leetcode.cn id=204 lang=python3
#
# [204] 计数质数
#

# @lc code=start
class Solution:
    # 线性筛：暂时略

    # 埃氏筛
    def countPrimes(self, n: int) -> int:
        isPrimes = [1] * n
        ans = 0
        for i in range(2, n):
            if isPrimes[i]:
                ans += 1
                if i * i <= n:
                    for j in range(i * i, n, i):
                        isPrimes[j] = 0
        return ans

    # 超时
    def countPrimes1(self, n: int) -> int:
        def isPrimes(n):
            i = 2
            while i * i <= n:
                if n % i == 0:
                    return 0
                i += 1
            return 1
        
        i = 2
        count = 0
        while i < n:
            count += isPrimes(i)
            i += 1
        return count

# Solution().countPrimes(10)
# @lc code=end

