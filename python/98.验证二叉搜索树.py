#
# @lc app=leetcode.cn id=98 lang=python3
#
# [98] 验证二叉搜索树
#


# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # bfs 迭代中序遍历
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True
        stack = list()
        in_order = float('-inf')
        while stack or root:
            while root:
                stack.append(root)
                root = root.left
            root = stack.pop()
            if root.val <= in_order:
                return False
            in_order = root.val
            root = root.right
        return True

    # dfs 递归
    def isValidBST1(self, root: Optional[TreeNode]) -> bool:

        def helper(root, lower=float('-inf'), upper=float('inf')):
            if not root:
                return True
            if root.val >= upper or root.val <= lower:
                return False
            if not helper(root.left, lower, root.val):
                return False
            if not helper(root.right, root.val, upper):
                return False
            return True

        return helper(root)


# 迭代实现树的三种遍历 https://blog.csdn.net/Netty711/article/details/124535792

# @lc code=end
