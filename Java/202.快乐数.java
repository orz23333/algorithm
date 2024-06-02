/*
 * @lc app=leetcode.cn id=202 lang=java
 *
 * [202] 快乐数
 */

// @lc code=start

import java.util.HashSet;

class Solution {
    public boolean isHappy(int n) {
        return m2(n);
    }

    /**
     * 模拟 + hashset去重
     */
    public boolean m1(int n) {
        HashSet<Integer> set = new HashSet<>();
        while (n != 1 && !set.contains(n)) {
            set.add(n);
            n = getNext(n);
        }
        return n == 1;
    }

    int getNext(int n) {
        int sum = 0;
        while (n > 0) {
            int num = n % 10;
            n /= 10;
            sum += num * num;
        }
        return sum;
    }

    /**
     * 模拟 + 快慢指南
     */
    public boolean m2(int n) {
        int fast = getNext(n);
        int slow = n;
        while (fast != 1 && fast != slow) {
            fast = getNext(getNext(fast));
            slow = getNext(slow);
        }
        return fast == 1;
    }
}
// @lc code=end
