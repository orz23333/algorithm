/*
 * @lc app=leetcode.cn id=334 lang=cpp
 *
 * [334] 递增的三元子序列
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
    bool increasingTriplet(vector<int>& nums)
    {
        return increasingTriplet2(nums);
    }

    /**
     * 贪心算法，尽量保证前两个值小.
     * 问题的关键在于保持second要比first要大，first出现的顺序不是最重要的。
     * 因为first或者first前面的值，都比second要小。
     * 把second值初始化为INT_MAX是非常巧妙的，使得在循环推进的过程中，首先要把second确定。
     */
    bool increasingTriplet2(vector<int>& nums)
    {
        int n      = nums.size();
        int first  = nums[0];
        int second = INT_MAX;
        for (int i = 1; i < n; i++) {
            int num = nums[i];
            if (num > second) {
                return true;
            }
            else if (num > first) {
                // 保证了second尽量小
                second = num;
            }
            else {
                // 保证了first比second小
                first = num;
            }
        }
        return false;
    }

    /**
     * 双向遍历，采用了分治的思想
     */
    bool increasingTriplet1(vector<int>& nums)
    {
        int n = nums.size();
        if (n < 3) {
            return false;
        }

        vector<int> leftMin(n);
        leftMin[0] = nums[0];
        for (int i = 1; i < n; i++) {
            leftMin[i] = min(leftMin[i - 1], nums[i]);
        }

        vector<int> rightMax(n);
        rightMax[n - 1] = nums[n - 1];
        for (int i = n - 2; i > 0; i--) {
            rightMax[i] = max(rightMax[i + 1], nums[i]);
        }

        for (int i = 0; i < n; i++) {
            if (leftMin[i] < nums[i] && nums[i] < rightMax[i]) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
