/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
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
    int climbStairs(int n)
    {
        int p = 0;
        int q = 0;
        int r = 1;
        for (int i = 1; i <= n; i++) {
            p = q;
            q = r;
            r = q + p;
        }
        return r;
    }

    /**
     * 自写，易于理解
    */
    int climbStairs2(int n)
    {
        if (n < 2) {
            return 1;
        }

        int step1 = 1;
        int step2 = 1;
        int pre;
        for (int i = 2; i <= n; i++) {
            int tmp = pre;
            pre = step1 + step2;
            step1 = step2;
            step2 = pre;
        }

        return pre;
    }   
};
// @lc code=end
