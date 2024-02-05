#
# @lc app=leetcode.cn id=79 lang=python3
#
# [79] 单词搜索
#


# @lc code=start
class Solution:

    def exist(self, board: List[List[str]], word: str) -> bool:
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        visited = set()

        def check(i, j, k):
            if board[i][j] != word[k]:
                return False
            if k == len(word) - 1:
                return True
            visited.add((i, j))
            result = False
            for di, dj in directions:
                newi = i + di
                newj = j + dj
                if 0 <= newi < len(board) and 0 <= newj < len(board[0]):
                    if (newi, newj) not in visited and check(
                            newi, newj, k + 1):
                        result = True
            visited.remove((i, j))
            return result

        h = len(board)
        w = len(board[0])
        for i in range(h):
            for j in range(w):
                if check(i, j, 0):
                    return True
        return False


# @lc code=end
