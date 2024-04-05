/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
// @lc code=start
class Automaton
{
    string state = "start";

    unordered_map<string, vector<string>> table = {
        {"start", {"start", "signed", "number", "end"}},
        {"signed", {"end", "end", "number", "end"}},
        {"number", {"end", "end", "number", "end"}},
        {"end", {"end", "end", "end", "end"}}};

    int get_col(char ch)
    {
        if (isspace(ch)) {
            return 0;
        }
        else if (ch == '+' || ch == '-') {
            return 1;
        }
        else if (isdigit(ch)) {
            return 2;
        }
        else {
            return 3;
        }
    }

public:
    int sign = 1;

    long long int ans = 0;

    void get(char ch)
    {
        state = table[state][get_col(ch)];

        if (state == "number") {
            ans = ans * 10 + ch - '0';
            // 这里不能改动ans为-ans，因为最终的答案要由automaton.ans * automaton.sign计算得出。
            // 把所有输入都当成正数来处理，方便逻辑统一。
            ans = sign == 1 ? min(ans, (long long)INT_MAX)
                            : min(ans, -(long long)INT_MIN);
        }
        else if (state == "signed") {
            sign = ch == '+' ? 1 : -1;
        }
    }
};


class Solution
{
public:
    // 自动机
    int myAtoi(string s)
    {
        Automaton automaton;
        for (char ch : s) {
            automaton.get(ch);
        }
        return automaton.ans * automaton.sign;
    }
};
// @lc code=end
int main()
{
    cout << (Solution()).myAtoi("   -42") << endl;
}