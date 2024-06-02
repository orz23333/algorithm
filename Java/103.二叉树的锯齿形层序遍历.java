
/*
 * @lc app=leetcode.cn id=103 lang=java
 *
 * [103] 二叉树的锯齿形层序遍历
 */
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.LinkedList;
import java.util.Queue;
import java.util.List;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode() {}
 * TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) {
 * this.val = val;
 * this.left = left;
 * this.right = right;
 * }
 * }
 */
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        boolean leftToRight = true;
        List<List<Integer>> res = new ArrayList<>();
        Queue<TreeNode> Q = new ArrayDeque<>();
        if (root != null) {
            Q.add(root);
        }

        while (!Q.isEmpty()) {
            Deque<Integer> levelList = new LinkedList<>();
            int size = Q.size();

            for (int i = 0; i < size; i++) {
                TreeNode node = Q.poll();

                if (leftToRight) {
                    levelList.offerLast(node.val);
                } else {
                    levelList.offerFirst(node.val);
                }

                if (node.left != null) {
                    Q.add(node.left);
                }

                if (node.right != null) {
                    Q.add(node.right);
                }
            }

            res.add(new LinkedList<>(levelList));
            leftToRight = !leftToRight;
        }

        return res;
    }
}
// @lc code=end
