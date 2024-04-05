/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */
#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int> nums;
        for (string s : tokens) {
            if (s == "+" || s == "-" || s == "/" || s == "*") {
                int num1 = nums.top();
                nums.pop();
                int num2 = nums.top();
                nums.pop();

                if (s == "+") {
                    nums.push(num1 + num2);
                }
                if (s == "-") {
                    nums.push(num2 - num1);
                }
                if (s == "*") {
                    nums.push(num1 * num2);
                }
                if (s == "/") {
                    nums.push(num2 / num1);
                }
            }
            else {
                int num = atoi(s.c_str());
                nums.push(num);
            }
        }
        return nums.top();
    }
};
// @lc code=end
int main()
{
    vector<string> tokens{
        "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << (Solution()).evalRPN(tokens) << endl;
}