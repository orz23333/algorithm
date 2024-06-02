/*
 * @lc app=leetcode.cn id=230 lang=java
 *
 * [230] 二叉搜索树中第K小的元素
 */

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
    public int kthSmallest(TreeNode root, int k) {
        int cnt = countNodes(root.left);

        if (cnt < k - 1) {
            return kthSmallest(root.right, k - cnt - 1);
        } else if (cnt > k - 1) {
            return kthSmallest(root.left, k);
        } else {
            return root.val;
        }
    }

    public int countNodes(TreeNode root) {
        if (root == null) {
            return 0;
        }

        int leftNode = countNodes(root.left);
        int rightNode = countNodes(root.right);

        return leftNode + rightNode + 1;
    }
}
// @lc code=end
