/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        return method1(nums);
    }

    // dp解法
    int method1(vector<int>& nums)
    {
        int pre = 0;
        int res = nums[0];
        for (auto num : nums) {
            pre = max(pre + num, num);
            res = max(pre, res);
        }
        return res;
    }

    // TODO 分治解法
};
// @lc code=end
