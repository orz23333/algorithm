/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
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
    // 暴力解法
    int strStr(string haystack, string needle)
    {
        int len1  = haystack.length();
        int len2  = needle.length();
        int index = -1;
        if (len1 < len2) {
            return index;
        }

        bool found = false;
        for (int i = 0; i <= len1 - len2; i++) {
            for (int j = 0; j < len2; j++) {
                if (needle[j] != haystack[j + i]) {
                    found = false;
                    break;
                }
                found = true;
            }
            if (found) {
                index = i;
                return index;
            }
        }
        return index;
    }

    // TODO: kmp算法，待定
};
// @lc code=end
