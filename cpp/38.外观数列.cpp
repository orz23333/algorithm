/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
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
    // 遍历生成
    string countAndSay(int n)
    {
        string pre = "1";

        for (int i = 2; i <= n; i++) {
            string curr;
            /**
             * 定义了一个start和一个pos非常巧妙，通过两者位置的差值，计算出个数
             * 避免了使用其他的结构来存储值和频次。
            */
            int start = 0;
            int pos   = 0;
            while (pos < pre.length()) {
                /**
                 * 因为start和pos是相同的，所以启动的时候总是能计算出当前值的个数
                 * 看似其他地方没有给pos赋值，实际通过start = pos，让外层的循环条件
                 * while (pos < pre.length())能够结束。
                */
                while (pos < pre.length() && pre[pos] == pre[start]) {
                    pos++;
                }
                curr += to_string(pos - start) + pre[start];
                start = pos;
            }
            pre = curr;
        }

        return pre;
    }
};
// @lc code=end
