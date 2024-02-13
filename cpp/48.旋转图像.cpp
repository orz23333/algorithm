/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
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
    void rotate(vector<vector<int>>& matrix)
    {
        method2(matrix);
    }

    // 辅助矩阵
    void method2(vector<vector<int>>& matrix)
    {
        int n     = matrix.size();
        auto copy = matrix;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                copy[j][n - 1 - i] = matrix[i][j];
            }
        }
        matrix = copy;
    }

    // 对折 + 翻转
    void method1(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        // 上下对折，注意要除二，否则会变回原样
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < n; j++) {
                swap(matrix[i][j], matrix[n - 1 - i][j]);
            }
        }

        // 对角线翻转，同理，只需要翻转一侧的数即可
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
// @lc code=end
