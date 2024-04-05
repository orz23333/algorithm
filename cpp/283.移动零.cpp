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
                /**
                 * 把移动了的位置，置为0。
                 * 因为ptrNotZero == i，即没移动的话，说明原来就不是0。无需处理。
                 * 移动了的话，即相当于0和当前位置的元素进行了互换。
                */
                nums[i] = ptrNotZero == i ? nums[i] : 0;
                ptrNotZero++;
            }
        }
    }
};
// @lc code=end
