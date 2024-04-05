/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
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
    int majorityElement(vector<int>& nums)
    {
        int pre   = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); i++) {
            count = nums[i] == pre ? count + 1 : count - 1;
            if (count == 0) {
                pre   = nums[i];
                count = 1;
            }
        }

        return pre;
    }

    // 方法一：排序取中间元素

    // 方法二，hash，取出现出现最多的元素

    // 方法三：分治
};
// @lc code=end
