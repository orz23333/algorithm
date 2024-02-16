/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
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
    int reverse(int x)
    {
        int base  = 0;
        int high  = INT_MAX / 10;
        int lower = INT_MIN / 10;

        while (x != 0) {
            if (base > high || base < lower) {
                return 0;
            }
            base = base * 10 + x % 10;
            x /= 10;
        }

        return base;
    }
};
// @lc code=end
