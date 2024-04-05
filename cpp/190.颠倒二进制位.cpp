/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stdint.h>
using namespace std;
// @lc code=start
class Solution {
public:
    /* 逐位翻转 */
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32 && n > 0; i++)
        {
            res |= (n & 1) << (31 - i);
            n >>= 1;
        }
        return res;
    }

    // TODO 分治
};
// @lc code=end
int main(int argc, char const *argv[])
{
    cout << (Solution()).reverseBits(43261596) << endl;
    return 0;
}

