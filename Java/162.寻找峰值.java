/*
 * @lc app=leetcode.cn id=162 lang=java
 *
 * [162] 寻找峰值
 */

// @lc code=start
class Solution {
    public int findPeakElement(int[] nums) {
        return m3(nums);
    }

    // 寻找最大值
    public int m1(int[] nums) {
        int idx = 0;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > nums[idx]) {
                idx = i;
            }
        }
        return idx;
    }

    // 迭代爬坡
    public int m2(int[] nums) {
        int idx = (int) (Math.random() * nums.length);
        while (!(compare(nums, idx - 1, idx) < 0 && compare(nums, idx, idx + 1) > 0)) {
            idx += (compare(nums, idx, idx + 1) < 0) ? 1 : -1;
        }
        return idx;
    }

    int compare(int[] nums, int idx1, int idx2) {
        int[] nums1 = get(nums, idx1);
        int[] nums2 = get(nums, idx2);

        if (nums1[0] != nums2[0]) {
            return nums1[0] - nums2[0];
        }

        return nums1[1] - nums2[1];
    }

    /**
     * 辅助函数，处理下标超界的问题
     */
    int[] get(int[] nums, int idx) {
        if (idx == -1 || idx == nums.length) {
            return new int[] { 0, 0 };
        }
        return new int[] { 1, nums[idx] };
    }

    // 迭代爬坡 + 二分查找优化
    public int m3(int[] nums) {
        int left = 0;
        int right = nums.length - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if ((compare(nums, mid - 1, mid) < 0 && compare(nums, mid, mid + 1) > 0)) {
                return mid;
            } else if (compare(nums, mid, mid + 1) > 0) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return -1;
    }
}
// @lc code=end
