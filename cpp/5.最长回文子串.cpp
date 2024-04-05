/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
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
    string longestPalindrome(string s)
    {
        return longestPalindrome2(s);
    }

    // TODO Manacher 算法

    /**
     * 动态规划
     * 回文天然支持转移方程
     * d[i][j]代表s[i, j]是否为一个回文串,
     * 转移方程为d[i][j] = s[i] == s[j] and d[i + 1][j - 1]
     * 通过画图可以知道，是通过斜对角线的方式来转移，因此竖向，再横向遍历
     */
    string longestPalindrome3(string s)
    {
        int len = s.length();
        if (len < 2) {
            return s;
        }

        int maxLen = 1;
        int begin  = 0;
        bool dp[len][len];

        // 初始化斜对角线
        for (int i = 0; i < len; i++) {
            dp[i][i] = true;
        }

        for (int j = 1; j < len; j++) {
            for (int i = 0; i < j; i++) {
                if (s[i] != s[j]) {
                    dp[i][j] = false;
                }
                else {
                    if (j - i < 3) {
                        dp[i][j] = true;
                    }
                    else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                if (dp[i][j] && j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    begin  = i;
                }
            }
        }
        return s.substr(begin, maxLen);
    }


    /**
     * 中心拓展法
     */
    string longestPalindrome2(string s)
    {
        int len    = s.length();
        int maxLen = 1;
        int begin  = 0;
        for (int i = 0; i < len - 1; i++) {
            int oddNum  = expandPalindromic(s, i, i);
            int evenNum = expandPalindromic(s, i, i + 1);

            int curMax = max(oddNum, evenNum);
            if (curMax > maxLen) {
                maxLen = curMax;
                // 回文串长度奇偶归一公式
                begin = i - (curMax - 1) / 2;
            }
        }
        return s.substr(begin, maxLen);
    }

    int expandPalindromic(string s, int mid1, int mid2)
    {
        int len = s.length();
        while (0 <= mid1 && mid2 < len) {
            if (s[mid1] != s[mid2]) {
                break;
            }
            else {
                mid1--;
                mid2++;
            }
        }
        return mid2 - mid1 - 1;
    }

    /**
     * 暴力法
     * 从下标零开始，分别以index为起始点，找长度为0...len的回文子串
     */
    string longestPalindrome1(string s)
    {
        int len = s.length();
        if (len < 2) {
            return s;
        }

        int begin  = 0;
        int maxLen = 1;

        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                if (j - i + 1 > maxLen && validPalindromic(s, i, j)) {
                    maxLen = j - i + 1;
                    begin  = i;
                }
            }
        }
        return s.substr(begin, maxLen);
    }

    bool validPalindromic(string& s, int left, int right)
    {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
// @lc code=end
