#
# @lc app=leetcode.cn id=36 lang=python3
#
# [36] 有效的数独
#
from typing import List


# @lc code=start
class Solution:

    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows = [[0 for _ in range(0, 9)] for _ in range(0, 9)]
        cols = [[0 for _ in range(0, 9)] for _ in range(0, 9)]
        subboxes = [[[0 for _ in range(0, 9)] for _ in range(0, 9)]
                    for _ in range(0, 9)]
        for i in range(0, 9):
            for j in range(0, 9):
                if board[i][j] != '.':
                    index = ord(board[i][j]) - ord('0') - 1
                    rows[i][index] += 1
                    cols[j][index] += 1
                    subboxes[i // 3][j // 3][index] += 1
                    if rows[i][index] > 1 or cols[j][index] > 1 or subboxes[
                            i // 3][j // 3][index] > 1:
                        return False
        return True


# Solution().isValidSudoku([["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]])
# @lc code=end
