/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
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
    int romanToInt(string s)
    {
        unordered_map<char, int> map = {{'I', 1},
                                        {'V', 5},
                                        {'X', 10},
                                        {'L', 50},
                                        {'C', 100},
                                        {'D', 500},
                                        {'M', 1000}};
        int res                      = 0;
        int n                        = s.length();
        for (int i = 0; i < n; i++) {
            if (i + 1 <= n - 1 && s[i] == 'I' &&
                (s[i + 1] == 'V' || s[i + 1] == 'X')) {
                res -= map[s[i]];
                continue;
            }
            if (i + 1 <= n - 1 && s[i] == 'X' &&
                (s[i + 1] == 'L' || s[i + 1] == 'C')) {
                res -= map[s[i]];
                continue;
            }
            if (i + 1 <= n - 1 && s[i] == 'C' &&
                (s[i + 1] == 'D' || s[i + 1] == 'M')) {
                res -= map[s[i]];
                continue;
            }
            res += map[s[i]];
        }
        return res;
    }
};
// @lc code=end
