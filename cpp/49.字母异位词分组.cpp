/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
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
    // 方法一：排序后的string作为key
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        if (strs.size() <= 0) {
            return {{}};
        }

        unordered_map<string, vector<string>> map;
        for (int i = 0; i < strs.size(); i++) {
            string cur = strs[i];
            sort(cur.begin(), cur.end());
            map[cur].emplace_back(strs[i]);
        }

        vector<vector<string>> result;
        for (auto item : map) {
            result.emplace_back(item.second);
        }

        return result;
    }

    // TODO 方法二：使用计数后的字母出现次数作为key，保证了匹配的准确性（类似1a3b4c）。
};
// @lc code=end
