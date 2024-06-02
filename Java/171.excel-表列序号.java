/*
 * @lc app=leetcode.cn id=171 lang=java
 *
 * [171] Excel 表列序号
 */

// @lc code=start
class Solution {
    public int titleToNumber(String columnTitle) {
        int res = 0;
        int multiple = 1;
        for (int i = columnTitle.length() - 1; i >= 0; i--) {
            int num = columnTitle.charAt(i) - 'A' + 1;
            res += num * multiple;
            multiple *= 26;
        }
        return res;
    }
}
// @lc code=end

