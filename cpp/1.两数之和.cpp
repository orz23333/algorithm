/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include <unordered_map>
#include <vector>

using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;
        for (int i = 0; i < nums.size(); i++) {
            int other_one = target - nums[i];
            auto found = hashmap.find(other_one);
            if (found != hashmap.end()) {
                return {i, found->second};
            }
            hashmap.insert(make_pair(nums[i], i));
        }
        return {};
    }
};
// @lc code=end

