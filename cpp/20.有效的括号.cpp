/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
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
    /**
     * 栈 + 表
     */
    bool isValid(string s)
    {
        if (s.size() % 2 != 0) {
            return false;
        }

        unordered_map<char, char> table{{'(', ')'}, {'[', ']'}, {'{', '}'}};

        vector<char> m_stack;
        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                m_stack.emplace_back(ch);
            }
            else {
                if (m_stack.empty()) {
                    return false;
                }
                char top = m_stack.back();
                m_stack.pop_back();
                if (table[top] != ch) {
                    return false;
                }
            }
        }
        return m_stack.empty();
    }
};
// @lc code=end
