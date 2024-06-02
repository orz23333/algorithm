/*
 * @lc app=leetcode.cn id=116 lang=java
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {
    }

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
// @lc code=start
/*
 * // Definition for a Node.
 * class Node {
 * public int val;
 * public Node left;
 * public Node right;
 * public Node next;
 * 
 * public Node() {}
 * 
 * public Node(int _val) {
 * val = _val;
 * }
 * 
 * public Node(int _val, Node _left, Node _right, Node _next) {
 * val = _val;
 * left = _left;
 * right = _right;
 * next = _next;
 * }
 * };
 */

class Solution {
    public Node connect(Node root) {
        if (root == null) {
            return null;
        }

        Node leftmostNode = root;

        while (leftmostNode.left != null) {
            Node head = leftmostNode;

            while (head != null) {
                head.left.next = head.right;

                if (head.next != null) {
                    head.right.next = head.next.left;
                }

                head = head.next;
            }

            leftmostNode = leftmostNode.left;
        }

        return root;
    }
}
// @lc code=end
