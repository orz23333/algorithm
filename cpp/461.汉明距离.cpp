/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
// @lc code=start
class Solution {
public:
    /**
     * Brian Kernighan 算法
    */
    int hammingDistance(int x, int y) {
        int count = 0;
        int n = x ^ y;
        while (n) {
            n &= n - 1;
            count++;
        }
        return count;
    }

    /**
     * O(log(n))
    */
    int hammingDistance2(int x, int y) {
        int count = 0;
        int n = x ^ y;
        while (n) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }

    /**
     * 自写,O(n)
    */
   int hammingDistance1(int x, int y) {
        int count = 0;
        for (int i = 0; i < 32; i++) {
            count = ((1 & x) ^ (1 & y)) ? count + 1 : count;
            x >>= 1;
            y >>= 1;
        }
        return count;
   }
};
// @lc code=end

