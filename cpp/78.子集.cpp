/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
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
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> combinations;
        vector<int> combination;

        dfs(combinations, combination, nums, 0);
        return combinations;
    }

    /**
     * 官解2：回溯法，每个数都有取或者不取两种状态
     */
    void dfs(vector<vector<int>>& combinations, vector<int>& combination,
             vector<int>& nums, int index)
    {
        if (index >= nums.size()) {
            combinations.emplace_back(combination);
            return;
        }

        // 不取当前数，进入下一个递归
        dfs(combinations, combination, nums, index + 1);

        // 取当前数，进入下一个递归
        combination.push_back(nums[index]);
        dfs(combinations, combination, nums, index + 1);
        combination.pop_back();
    }

    /**
     * 官解1：迭代法，每个数都有取或者不取两种状态
     */
    vector<vector<int>> bfs(vector<int>& nums)
    {
        vector<vector<int>> combinations;
        for (int mask = 0; mask < (1 << nums.size()); mask++) {
            vector<int> combination;
            for (int i = 0; i < nums.size(); i++) {
                if ((1 << i) & mask) {
                    combination.push_back(nums[i]);
                }
            }
            combinations.emplace_back(combination);
            combination.clear();
        }
        return combinations;
    }

    vector<vector<int>> method1(vector<int>& nums)
    {
        vector<vector<int>> combinations;
        vector<int> combination;

        for (int i = 0; i <= nums.size(); i++) {
            backtrack1(combinations, combination, nums, 0, i);
        }
        return combinations;
    }

    /**
     * index表示取数的下标起始点。与平常的回溯题，表示的已取的数的数量不同。
     */
    void backtrack1(vector<vector<int>>& combinations, vector<int>& combination,
                    vector<int>& nums, int index, int size)
    {
        if (combination.size() >= size) {
            combinations.emplace_back(combination);
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            combination.push_back(nums[i]);
            backtrack1(combinations, combination, nums, i + 1, size);
            combination.pop_back();
        }
    }
};
// @lc code=end
int main()
{
    vector<int> out = {1, 2, 3};
    (Solution()).subsets(out);
}