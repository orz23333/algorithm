/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        return method2(nums);
    }

    // 不借助额外数组，减少了一点空间复杂度，生成的结果是乱序的
    vector<vector<int>> method2(vector<int>& nums)
    {
        vector<vector<int>> ans;
        backtrack2(ans, nums, 0);
        return ans;
    }

    void backtrack2(vector<vector<int>>& combinations, vector<int>& combination,
                    int index)
    {
        // 原容器的大小不变，所以可以使用size，不然需要再构造一个入参表示总长度
        if (index == combination.size()) {
            combinations.emplace_back(combination);
            return;
        }

        /**
         * index表示已经待填的下标，index左边的值都是已经使用过的，
         * index及index右边的是未使用过的
        */
        for (int i = index; i < combination.size(); i++) {
            /**
             * 因为使用了原数据作为组合结果的容器，所以执行这一步交换，
             * 就相当于是使用了一个数据。所以需要将使用了的数据交换到index的位置，
             * 表示已经使用。
            */
            swap(combination[i], combination[index]);
            backtrack2(combinations, combination, index + 1);
            swap(combination[i], combination[index]);
        }
    }



    vector<vector<int>> method1(vector<int>& nums)
    {
        int n = nums.size();
        vector<vector<int>> combinations;
        vector<int> combination;
        vector<bool> used(n, false);
        backtrack1(combinations, combination, used, nums, 0);
        return combinations;
    }

    // 借助一个use标记数组，生成的结果是字典序的
    void backtrack1(vector<vector<int>>& combinations, vector<int>& combination,
                    vector<bool>& used, vector<int>& nums, int index)
    {
        if (index == nums.size()) {
            combinations.push_back(combination);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                combination.push_back(nums[i]);
                used[i] = true;
                backtrack1(combinations, combination, used, nums, index + 1);
                combination.pop_back();
                used[i] = false;
            }
        }
    }
};
// @lc code=end
