/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    void moveZeroes(vector<int>& nums) {
        method1(nums);
    }

    // 双指针
    void method1(vector<int>& nums)
    {
        int ptrNotZero = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[ptrNotZero] = nums[i];
                nums[i] = ptrNotZero == i ? nums[i] : 0;
                ptrNotZero++;
            }
        }
    }
};
// @lc code=end
