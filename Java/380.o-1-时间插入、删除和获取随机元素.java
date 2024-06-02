
/*
 * @lc app=leetcode.cn id=380 lang=java
 *
 * [380] O(1) 时间插入、删除和获取随机元素
 */
import java.util.List;
import java.util.Map;
import java.util.Random;
import java.util.ArrayList;
import java.util.HashMap;

// @lc code=start
class RandomizedSet {

    List<Integer> nums;
    Map<Integer, Integer> map;
    Random random;

    public RandomizedSet() {
        nums = new ArrayList<>();
        map = new HashMap<>();
        random = new Random();
    }

    public boolean insert(int val) {
        if (map.containsKey(val)) {
            return false;
        }
        int idx = nums.size();
        nums.add(val);
        map.put(val, idx);
        return true;
    }

    public boolean remove(int val) {
        if (!map.containsKey(val)) {
            return false;
        }

        int idx = map.get(val);
        int last = nums.get(nums.size() - 1);

        nums.set(idx, last);
        nums.remove(nums.size() - 1);

        map.put(last, idx);
        map.remove(val);

        return true;
    }

    public int getRandom() {
        int idx = random.nextInt(nums.size());
        return nums.get(idx);
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
// @lc code=end
