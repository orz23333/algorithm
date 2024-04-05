/*
 * @lc app=leetcode.cn id=412 lang=cpp
 *
 * [412] Fizz Buzz
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
    vector<string> fizzBuzz(int n)
    {
        vector<string> res;

        for (int i = 1; i <= n; i++) {
            string cur;
            if (i % 3 == 0) {
                cur += "Fizz";
            }
            if (i % 5 == 0) {
                cur += "Buzz";
            }
            if (cur.empty()) {
                cur += to_string(i);
            }
            res.emplace_back(cur);
        }

        return res;
    }

    /**
     * 存在重复计算的问题。
     */
    vector<string> fizzBuzz2(int n)
    {
        vector<string> res;

        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0 && i % 5 == 0) {
                res.push_back("FizzBuzz");
            }
            else if (i % 3 == 0) {
                res.push_back("Fizz");
            }
            else if (i % 5 == 0) {
                res.push_back("Buzz");
            }
            else {
                res.push_back(to_string(i));
            }
        }

        return res;
    }
};
// @lc code=end
