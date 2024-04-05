/*
 * @lc app=leetcode.cn id=384 lang=cpp
 *
 * [384] 打乱数组
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> origin;
    vector<int> num;

    Solution(vector<int>& nums) {
        this->num = nums;
        this->origin.resize(nums.size());
        copy(nums.begin(), nums.end(), origin.begin());
    }
    
    vector<int> reset() {
        copy(origin.begin(), origin.end(), num.begin());
        return num;
    }
    
    vector<int> shuffle() {
        for (int i = 0; i < num.size(); i++) {
            int j = i + rand() % (num.size() - i);
            swap(num[i], num[j]);
        }
        return num;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end

