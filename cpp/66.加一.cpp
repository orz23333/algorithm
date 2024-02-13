/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> plusOne(vector<int>& digits)
    {
        return method2(digits);
    }

    // 利用只+1的性质，所以进位也只可能是1
    vector<int> method2(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            digits[i] = (digits[i] + 1) % 10;
            if (digits[i] != 0) {
                return digits;
            }
        }
        // 能走到这里，说明每一位都进位了(e.g. 999)，结果的长度会+1
        vector<int> ans(digits.size() + 1, 0);
        ans[0] = 1;
        return ans;
    }

    // 相对通用的解法，加多少都可以
    vector<int> method1(vector<int>& digits) {
        vector<int> ans;
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            int cur = (digits[i] + carry) % 10;
            carry   = (digits[i] + carry) / 10;
            ans.push_back(cur);
        }
        if (carry > 0) {
            ans.push_back(carry);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end
