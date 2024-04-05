/*
 * @lc app=leetcode.cn id=326 lang=cpp
 *
 * [326] 3 的幂
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
    // 取巧
    bool isPowerOfThree(int n)
    {
        long long maxPowerOfThree = 1;
        long long maxNum          = (2LL << 30) - 1;
        while ((maxPowerOfThree = maxPowerOfThree * 3) < maxNum) {
            ;
        }
        return n > 0 && maxPowerOfThree % n == 0;
    }

    // 迭代
    bool isPowerOfThree1(int n)
    {
        while (n && n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
    }
};
// @lc code=end
int main()
{
    (Solution()).isPowerOfThree(10);
}