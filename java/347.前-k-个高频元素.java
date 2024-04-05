/*
 * @lc app=leetcode.cn id=347 lang=java
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;

class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        return topKFrequent2(nums, k);
    }

    // 小顶堆
    public int[] topKFrequent1(int[] nums, int k) {
        Map<Integer, Integer> occurrences = new HashMap<>();
        for (int num : nums) {
            occurrences.put(num, occurrences.getOrDefault(num, 0) + 1);
        }

        PriorityQueue<int[]> queue = new PriorityQueue<>(new Comparator<int[]>() {
            public int compare(int[] m, int[] n) {
                return m[1] - n[1];
            }
        });

        for (Map.Entry<Integer, Integer> entry : occurrences.entrySet()) {
            int num = entry.getKey();
            int count = entry.getValue();
            if (queue.size() >= k) {
                if (count > queue.peek()[1]) {
                    queue.poll();
                    queue.offer(new int[] { num, count });
                }
            } else {
                queue.offer(new int[] { num, count });
            }
        }

        int[] res = new int[k];
        for (int i = 0; i < k; i++) {
            res[i] = queue.poll()[0];
        }
        return res;
    }

    // 快排
    public int[] topKFrequent2(int[] nums, int k) {
        Map<Integer, Integer> occurrences = new HashMap<>();
        for (int num : nums) {
            occurrences.put(num, occurrences.getOrDefault(num, 0) + 1);
        }

        List<int[]> values = new ArrayList<>();
        for (Map.Entry<Integer, Integer> entry : occurrences.entrySet()) {
            values.add(new int[] { entry.getKey(), entry.getValue() });
        }

        int[] res = new int[k];
        qsort(values, 0, values.size() - 1, res, 0, k);
        return res;
    }

    void qsort(List<int[]> values, int start, int end, int[] res, int kstart, int k) {
        int picked = (int) Math.random() * (end - start + 1) + start;
        Collections.swap(values, picked, start);

        int pivot = values.get(start)[1];
        int index = start;

        for (int i = start + 1; i <= end; i++) {
            if (values.get(i)[1] >= pivot) {
                // 频数大的放左边，频数小的放右边
                Collections.swap(values, i, index + 1);
                index++;
            }
        }
        // 更正pivot的位置，至此，左边都大，右边都小
        Collections.swap(values, start, index);

        /**
         * 判断k和左子数组的关系，为使得只遍历分支的一边，我们将添加结果的逻辑，放在k >= 左侧数组长度的时候
         */
        if (k < index - start - 1) {
            qsort(values, start, index - 1, res, kstart, k);
        } else {
            for (int i = start; i <= index; i++) {
                res[kstart++] = values.get(i)[0];
            }
            if (k > index - start + 1) {
                qsort(values, index + 1, end, res, kstart, k - (index - start + 1));
            }
        }
    }
}
// @lc code=end
