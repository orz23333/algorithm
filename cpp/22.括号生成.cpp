/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
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
    vector<string> generateParenthesis(int n)
    {
        vector<string> combinations;

        string combination;
        // backtrack1(combinations, combination, 0, n, 0);
        backtrack2(combinations, combination, 0, 0, n);

        return combinations;
    }

    // 官解
    void backtrack2(vector<string>& combinations, string& combination, int open,
                    int close, int n)
    {
        if (combination.size() == n * 2) {
            combinations.push_back(combination);
            return;
        }

        if (open < n) {
            combination.push_back('(');
            backtrack2(combinations, combination, open + 1, close, n);
            combination.pop_back();
        }

        if (close < open) {
            combination.push_back(')');
            backtrack2(combinations, combination, open, close + 1, n);
            combination.pop_back();
        }
    }

    // 自写
    void backtrack1(vector<string>& combinations, string& combination,
                    int index, int n, int remained)
    {
        if (index == n * 2) {
            if (remained == 0) {
                combinations.push_back(combination);
            }
            return;
        }

        combination.push_back('(');
        backtrack1(combinations, combination, index + 1, n, remained + 1);
        combination.pop_back();

        if (remained > 0) {
            combination.push_back(')');
            backtrack1(combinations, combination, index + 1, n, remained - 1);
            combination.pop_back();
        }
    }
};
// @lc code=end
