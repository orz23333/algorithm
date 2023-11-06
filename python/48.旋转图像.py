#
# @lc app=leetcode.cn id=48 lang=python3
#
# [48] 旋转图像
#


# @lc code=start
class Solution:
    # 用翻转代替旋转
    def rotate(self, matrix: List[List[int]]) -> None:
        n = len(matrix)
        # 水平翻转
        for i in range(n // 2):
            for j in range(n):
                matrix[i][j], matrix[n - i - 1][j] = matrix[n - i -
                                                            1][j], matrix[i][j]

        # 对角线翻转
        for i in range(n):
            for j in range(i):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

    # 原地旋转
    def rotate2(self, matrix: List[List[int]]) -> None:
        n = len(matrix)
        for i in range(n // 2):
            for j in range((n + 1) // 2):
                temp = matrix[i][j]
                matrix[i][j] = matrix[n - j - 1][i]
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1]
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1]
                matrix[j][n - i - 1] = temp

    # 复制数组，考虑旋转后每行的规律
    def rotate1(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        copy = [[0] * n for _ in range(n)]
        for i in range(n):
            for j in range(n):
                copy[j][n - i - 1] = matrix[i][j]
        matrix[:] = copy


# @lc code=end
