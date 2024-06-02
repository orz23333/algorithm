/*
 * @lc app=leetcode.cn id=166 lang=java
 *
 * [166] 分数到小数
 */

// @lc code=start

import java.util.HashMap;
import java.util.Map;

class Solution {
    // 长除法
    public String fractionToDecimal(int numerator, int denominator) {
        long numeratorLong = (long)numerator;
        long denominatorLong = (long)denominator;

        if (numeratorLong % denominatorLong == 0) {
            return String.valueOf(numeratorLong / denominatorLong);
        }

        StringBuffer sb = new StringBuffer();

        // 符号部分
        if (numerator < 1 ^ denominator < 1) {
            sb.append('-');
        }

        // 整数部分
        numeratorLong = Math.abs(numeratorLong);
        denominatorLong = Math.abs(denominatorLong);
        sb.append(numeratorLong / denominatorLong);

        // 小数部分
        sb.append('.');
        StringBuffer fraction = new StringBuffer();
        Map<Long, Integer> remainderIndexHash = new HashMap<>();
        long remainder = numeratorLong % denominatorLong;
        int index = 0;
        while (remainder != 0 && !remainderIndexHash.containsKey(remainder)) {
            remainderIndexHash.put(remainder, index);
            remainder *= 10;
            fraction.append(remainder / denominatorLong);
            remainder %= denominatorLong;
            index++;
        }

        if (remainder != 0) {
            int circleBegin =remainderIndexHash.get(remainder);
            fraction.insert(circleBegin, '(');
            fraction.append(')');
        }

        sb.append(fraction);
        return sb.toString();
    }
}
// @lc code=end

