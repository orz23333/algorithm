/*
 * @lc app=leetcode.cn id=215 lang=java
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start

import java.util.PriorityQueue;

class Solution {
    public int findKthLargest(int[] nums, int k) {
        return m3(nums, k);
    }

    // 快排
    public int m1(int[] nums, int k) {
        return qsort(nums, 0, nums.length - 1, nums.length - k);
    }
    int qsort(int[] nums, int l, int r, int k) {
        if (l == r) {
            // 此时，l == r == k
            return nums[k];
        }
        // 取第一个值为基准值
        int x = nums[l];
        // 因为采用了do-while循环，所以使用此赋值
        int i = l - 1;
        int j = r + 1;
        while (i < j) {
            // do-while保证了不会死循环
            do {
                i++;
            } while (nums[i] < x);

            do {
                j--;
            } while (nums[j] > x);

            if (i < j) {
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }

        if (k <= j) {
            return qsort(nums, l, j, k);
        } else {
            return qsort(nums, j + 1, r, k);
        }
    }

    // 小堆 api
    public int m2(int[] nums, int k) {
        PriorityQueue<Integer> queue = new PriorityQueue<>((i1, i2) -> i1 - i2);

        int length = nums.length;
        for (int i = 0; i < length; i++) {
            queue.offer(nums[i]);
            if (queue.size() > k) {
                queue.poll();
            }
        }

        return queue.poll();
    }

    // TODO 小堆 自写
    public int m3(int[] nums, int k) {
        return -1;
    }
}
// @lc code=end
