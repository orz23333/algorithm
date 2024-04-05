/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
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
    int lengthOfLongestSubstring(string s)
    {
        // 哈希集合，记录每个字符是否出现过
        unordered_set<char> occ;
        int n = s.size();
        // 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
        int rk = -1, ans = 0;
        // 枚举左指针的位置，初始值隐性地表示为 -1
        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                // 左指针向右移动一格，移除一个字符
                occ.erase(s[i - 1]);
            }
            while (rk + 1 < n && !occ.count(s[rk + 1])) {
                // 不断地移动右指针
                occ.insert(s[rk + 1]);
                ++rk;
            }
            // 第 i 到 rk 个字符是一个极长的无重复字符子串
            ans = max(ans, rk - i + 1);
        }
        return ans;
    }

    /**
     * 自写：不断移动右指针，碰到重复字符后，移动左指针，直到没有重复字符。
     */
    int lengthOfLongestSubstring1(string s)
    {
        unordered_map<char, int> table;
        int maxLen = 0;
        int n      = s.length();
        int left   = 0;
        int right  = 0;
        while (right < n) {
            while (table[s[right]]) {
                table[s[left]] = table[s[left]] > 0 ? table[s[left]] - 1 : 0;
                left++;
            }

            table[s[right]] += 1;
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};
// @lc code=end
int main(int argc, char const* argv[])
{
    (Solution()).lengthOfLongestSubstring("pwwkew");
    return 0;
}
