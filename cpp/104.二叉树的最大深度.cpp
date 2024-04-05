/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 */
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        return bfs_ans(root);
    }

    int bfs_ans(TreeNode* root) {
        if (!root) {
            return 0;
        }

        queue<TreeNode*> Q;
        Q.push(root);
        int max_depth = 0;
        while (Q.size()) {
            max_depth++;
            int cur_level = Q.size();
            for (int i = 0; i < cur_level; i++) {
                TreeNode* cur = Q.front();
                if (cur->left) {
                    Q.push(cur->left);
                }
                if (cur->right) {
                    Q.push(cur->right);
                }
                Q.pop();
            }
        }
        return max_depth;
    }

    int dfs_ans(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return max(dfs_ans(root->left), dfs_ans(root->right)) + 1;
    }

    // 自研
    int dfs_self(TreeNode* root, int depth) {
        if (!root) {
            return max_depth;
        }

        depth++;
        max_depth = max(depth, max_depth);
        dfs_self(root->left, depth);
        dfs_self(root->right, depth);
        return max_depth;
    }

public:
    int max_depth = 0;
};
// @lc code=end

