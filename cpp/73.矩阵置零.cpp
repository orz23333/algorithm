/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */
#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    // 使用位标记
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        // 使用第一行和第一列来标记对应位置是否为0，但是仅使用一个标记变量
        bool flag_col0 = false;

        for (int i = 0; i < m; i++) {
            if (!matrix[i][0]) {
                // 只要第一列有一个0，那么整个列最后会被置为0
                flag_col0 = true;
            }
            for (int j = 1; j < n; j++) {
                if (!matrix[i][j]) {
                    // 标记行列对应位置是否为0
                    // 第一列位置有flag_col0来保证原来顺序。
                    // 第一行位置则会由后面行是否为0来决定，覆写了也无所谓。
                    // 如果后面的行都是1，则没有改写自身，可以由自身的数据来存储结果
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        // 倒序来设置变量值，因为第一行是用来对应列值有否有0.不能被提前更改
        for (int i = m - 1; i >= 0; i--) {
            for (int j = 1; j < n; j++) {
                if (!matrix[i][0] || !matrix[0][j]) {
                    matrix[i][j] = 0;
                }
            }

            // 因为matrix[i][0]在上一步要使用，所以需要在下面进行设置
            if (flag_col0) {
                matrix[i][0] = 0;
            }
        }
    }

    // 非原地算法
    void setZeroes2(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        // 保存行的0值
        vector<int> vRow(row, 1);
        // 保存列的0值
        vector<int> vCol(col, 1);

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (matrix[r][c] == 0) {
                    vRow[r] = 0;
                    vCol[c] = 0;
                }
            }
        }

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (vRow[r] == 0 || vCol[c] == 0) {
                    matrix[r][c] = 0;
                }
            }
        }

    }
};
// @lc code=end
int main()
{
    vector<vector<int>> martix = {{1,1,1},{1,0,1},{1,1,1}};
    
    (Solution()).setZeroes(martix);
}
