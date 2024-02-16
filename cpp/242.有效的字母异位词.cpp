/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
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
    bool isAnagram(string s, string t)
    {
        return method2(s, t);
    }

    /**
     * hash表计算频次（unicode同样适用）
     */
    bool method2(string s, string t)
    {
        int m = s.length();
        int n = t.length();
        if (m != n) {
            return false;
        }
        unordered_map<char, int> map;

        for (int i = 0; i < m; i++) {
            map[s[i]]++;
        }

        for (int i = 0; i < n; i++) {
            if (--map[t[i]] < 0) {
                return false;
            }
        }
        return true;
    }

    /**
     * 排序
     */
    bool method1(string s, string t)
    {
        if (s.length() != t.length()) {
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        if (s == t) {
            return true;
        }

        return false;
    }
};
// @lc code=end
