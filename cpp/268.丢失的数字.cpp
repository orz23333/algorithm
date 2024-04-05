/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
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
    int missingNumber(vector<int>& nums)
    {
        int sum = 0;
        int n   = nums.size();
        for (int num : nums) {
            sum += num;
        }
        return (n + 1) * n / 2 - sum;
    }

    // TODO 1、排序 2、hash 3、异或
};
// @lc code=end
