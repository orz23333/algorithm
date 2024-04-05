/*
 * @lc app=leetcode.cn id=75 lang=java
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
    public void sortColors(int[] nums) {
        int n = nums.length;
        int p0 = 0;
        int p2 = n - 1;
        int ptr = 0;

        while (ptr <= p2) {
            while (ptr <= p2 && nums[ptr] == 2) {
                swap(nums, p2, ptr);
                p2--;
            }

            if (nums[ptr] == 0) {
                swap(nums, p0, ptr);
                p0++;
            }
            ptr++;
        }
    }

    private void swap(int[] nums, int num1, int num2) {
        int tmp = nums[num1];
        nums[num1] = nums[num2];
        nums[num2] = tmp;
    }
}

// @lc code=end
