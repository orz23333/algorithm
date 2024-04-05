/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
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
    int rob(vector<int>& nums)
    {
        if (nums.size() == 1) {
            return nums[0];
        }

        int pre     = max(nums[0], nums[1]);
        int pre_pre = nums[0];
        int ans = pre;

        for (int i = 2; i < nums.size(); i++) {
            ans = max(pre_pre + nums[i], pre);
            pre_pre = pre;
            pre = ans;
        }

        return ans;
    }

    /**
     * 自写
    */
    int rob2(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        int steal_max     = nums[0];
        int pre_steal_max = nums[0];

        int not_steal_max     = 0;
        int pre_not_steal_max = 0;

        for (int i = 1; i < nums.size(); i++) {
            steal_max     = max(pre_steal_max, pre_not_steal_max + nums[i]);
            not_steal_max = max(pre_steal_max, pre_not_steal_max);

            pre_steal_max     = steal_max;
            pre_not_steal_max = not_steal_max;
        }

        return max(steal_max, not_steal_max);
    }
};
// @lc code=end
