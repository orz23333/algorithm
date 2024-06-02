/*
 * @lc app=leetcode.cn id=172 lang=java
 *
 * [172] 阶乘后的零
 */

// @lc code=start
class Solution {
    public int trailingZeroes(int n) {
        return m2(n);
    }

    /**
     * 常规
     */
    public int m1(int n) {
        int count = 0;
        for (int i = 5; i <= n; i++) {
            for (int j = i; j % 5 == 0; j /= 5) {
                count++;
            }
        }
        return count;
    }

    /**
     * 优化计算
     */
    public int m2(int n) {
        int count = 0;
        while (n != 0) {
            n /= 5;
            count += n;
        }
        return count;
    }
}
// @lc code=end