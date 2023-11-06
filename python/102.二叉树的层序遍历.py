#
# @lc app=leetcode.cn id=102 lang=python3
#
# [102] 二叉树的层序遍历
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
    # bfs
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return list()
        queue = collections.deque()
        queue.append(root)
        ans = list()
        while queue:
            cur = list()
            n = len(queue)
            for _ in range(n):
                node = queue.popleft()
                cur.append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            ans.append(cur)
        return ans


# @lc code=end
