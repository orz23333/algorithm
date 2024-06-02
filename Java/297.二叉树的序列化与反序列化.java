
/*
 * @lc app=leetcode.cn id=297 lang=java
 *
 * [297] 二叉树的序列化与反序列化
 */
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        return rserialize(root, "");
    }

    private String rserialize(TreeNode node, String str) {
        if (node == null) {
            str = "none";
        } else {
            str = String.valueOf(node.val);
            str += "," + rserialize(node.left, str);
            str += "," + rserialize(node.right, str);
        }
        return str;
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        String[] dataArray = data.split(",");
        List<String> list = new ArrayList<>(Arrays.asList(dataArray));
        return rdeserialize(list);
    }

    private TreeNode rdeserialize(List<String> list) {
        if (list.get(0).equals("none")) {
            list.remove(0);
            return null;
        }

        TreeNode node = new TreeNode(Integer.valueOf(list.get(0)));
        list.remove(0);
        node.left = rdeserialize(list);
        node.right = rdeserialize(list);
        return node;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));
// @lc code=end
