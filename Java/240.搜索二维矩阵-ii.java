/*
 * @lc app=leetcode.cn id=240 lang=java
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        return m3(matrix, target);
    }

    /**
     * 暴力
     */
    public boolean m1(int[][] matrix, int target) {
        int m = matrix.length;
        int n = matrix[0].length;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == target) {
                    return true;
                }
            }
        }
        return false;
    }

    /**
     * 二分
     */
    public boolean m2(int[][] matrix, int target) {
        int m = matrix.length;
        for (int i = 0; i < m; i++) {
            if (binarySearch(matrix[i], target)) {
                return true;
            }
        }
        return false;
    }

    boolean binarySearch(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return true;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return false;
    }

    /**
     * Z字搜索，充分利用升降序的特点，从右上角或者左下角可以遍历都可以
     */
    public boolean m3(int[][] matrix, int target) {
        int m = matrix.length;
        int n = matrix[0].length;
        int row = m - 1;
        int col = 0;
        while (row >= 0 && col <= n - 1) {
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] < target) {
                col++;
            } else {
                row--;
            }
        }
        return false;
    }
}
// @lc code=end
