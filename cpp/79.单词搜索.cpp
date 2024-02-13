/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
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
    int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool exist(vector<vector<char>>& board, string word)
    {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> used(m, vector<bool>(n, false));

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (backtrack(board, word, used, row, col, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    /**
     * 切记，能够复用原有容器就复用原有容器，减少内存使用量。
     * 例如通过交换位置（全排列），取下标值对比等方式（单词搜索）
     * 
     * c++传参使用引用的方式，不然每次递归都会复制一个内存。
     * c++的=号不是引用赋值，而是值赋值！！！
    */
    bool backtrack(vector<vector<char>>& board, string& word,
                   vector<vector<bool>>& used, int row, int col, int index)
    {
        if (board[row][col] != word[index]) {
            return false;
        }

        if (index == word.length() - 1) {
            return true;
        }

        used[row][col] = true;
        for (int i = 0; i < 4; i++) {
            int new_row = row + direction[i][0];
            int new_col = col + direction[i][1];
            if (new_row >= 0 && new_row < board.size() && new_col >= 0 &&
                new_col < board[0].size() && !used[new_row][new_col]) {
                if (backtrack(board, word, used, new_row, new_col, index + 1)) {
                    return true;
                }
            }
        }
        used[row][col] = false;

        return false;
    }
};
// @lc code=end
