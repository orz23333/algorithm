/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
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
    bool isValidSudoku(vector<vector<char>>& board)
    {
        return method1(board);
    }

    // 模拟 + 数组记录数字的计数
    bool method1(vector<vector<char>>& board)
    {
        // 重点在于这个数据结构表示。因为只有9行9列，因此只需要固定长度数组
        int rows[9][9]        = {0};
        int cols[9][9]        = {0};
        // 小方块的数据表示尤其重要。通过i，j的位置就可以推算出是哪个小方块
        int subboxes[3][3][9] = {0};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int index = board[i][j] - '0' - 1;
                    rows[i][index] += 1;
                    cols[j][index] += 1;
                    subboxes[i / 3][j / 3][index] += 1;

                    if (rows[i][index] > 1 || cols[j][index] > 1 ||
                        subboxes[i / 3][j / 3][index] > 1) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};
// @lc code=end
