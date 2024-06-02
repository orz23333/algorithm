/*
 * @lc app=leetcode.cn id=50 lang=java
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
    public double myPow(double x, int n) {
        return myPow2(x, n);
    }

    // 快速幂 + 递归
    public double myPow1(double x, int n) {
        long N = n;
        return n > 0 ? dfs(x, N) : 1.0 / dfs(x, -N);
    }

    private double dfs(double x, long n) {
        if (n == 0) {
            return 1.0;
        }

        double y = dfs(x, n / 2);
        return n % 2 == 0 ? y * y : y * y * x;
    }


    // 快速幂 + 迭代
    public double myPow2(double x, int n) {
        long N = n;
        return n > 0 ? bfs(x, N) : 1.0 / bfs(x, -N);
    }
    
    private double bfs(double x, long n) {
        double ans = 1.0;
        double base = x;
        while (n > 0) {
            if ((n & 1) == 1) {
                ans *= base;
            }
            base *= base;
            n >>= 1;
        }
        return ans;
    }
}
// @lc code=end

