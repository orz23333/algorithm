/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
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
    // 回溯
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        if (digits.length() == 0) {
            return ans;
        }

        unordered_map<char, string> phoneMap{{'2', "abc"},
                                             {'3', "def"},
                                             {'4', "ghi"},
                                             {'5', "jkl"},
                                             {'6', "mno"},
                                             {'7', "pqrs"},
                                             {'8', "tuv"},
                                             {'9', "wxyz"}};

        string combination;
        backtrace(ans, phoneMap, digits, 0, combination);
        return ans;
    }

    void backtrace(vector<string>& ans, unordered_map<char, string>& phoneMap, string& digits,
                   int index, string& combination)
    {
        if (index == digits.length()) {
            ans.push_back(combination);
            return;
        }

        char curNum = digits[index];
        auto curMap = phoneMap[curNum];
        for (int i = 0; i < curMap.length(); i++) {
            combination.push_back(curMap[i]);
            backtrace(ans, phoneMap, digits, index + 1, combination);
            combination.pop_back();
        }
    }
};
// @lc code=end
