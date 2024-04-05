/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
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
    string longestCommonPrefix(vector<string>& strs)
    {
        int count  = strs.size();
        int length = strs[0].length();
        for (int i = 0; i < length; i++) {
            for (int j = 1; j < count; j++) {
                if (i == strs[j].length() || strs[j][i] != strs[0][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }

    // 自写，纵向扫描，包含了很多重复代码
    string method1(vector<string>& strs)
    {
        string ans;

        for (int i = 0; i < strs[0].length(); i++) {
            bool same = true;
            for (int j = 0; j < strs.size(); j++) {
                if (same && i < strs[j].length() && strs[0][i] == strs[j][i]) {
                    continue;
                }
                else {
                    same = false;
                    break;
                }
            }
            if (same) {
                ans.push_back(strs[0][i]);
            }
            else {
                break;
            }
        }

        return ans;
    }
};
// @lc code=end
