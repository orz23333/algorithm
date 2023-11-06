#
# @lc app=leetcode.cn id=101 lang=python3
#
# [101] 对称二叉树
#
import collections


# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        return self.bfs(root, root)

    # 递归
    def bfs(self, left, right):
        queue = collections.deque()
        queue.extend([left, right])
        while queue:
            node1 = queue.popleft()
            node2 = queue.popleft()

            if not node1 and not node2:
                continue
            elif (not node1 or not node2) or node1.val != node2.val:
                return False

            queue.append(node1.left)
            queue.append(node2.right)
            queue.append(node1.right)
            queue.append(node2.left)
        return True

    # 迭代
    def dfs(self, left, right):
        if not left and not right:
            return True
        elif not left or not right:
            return False
        else:
            return left.val == right.val and self.dfs(
                left.left, right.right) and self.dfs(left.right, right.left)


# @lc code=end
