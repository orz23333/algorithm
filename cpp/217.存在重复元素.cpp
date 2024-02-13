/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return method2(nums);
    }

    // hash表
    bool method2(vector<int>& nums) {
        unordered_set<int> set;
        for (int i = 0; i < nums.size(); i++) {
            if (set.count(nums[i]) != 0) {
                return true;
            }
            set.insert(nums[i]);
        }
        return false;
    }
    
    // 排序
    bool method1(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int pre = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

