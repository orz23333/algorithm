/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */
#include <queue>
using namespace std;

struct TreeNode
{
    int       val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
        : val(0)
        , left(nullptr)
        , right(nullptr)
    {}
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x)
        , left(left)
        , right(right)
    {}
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
    bool isSymmetric(TreeNode* root)
    {
        return bfs_two_points(root);
    }

    // bfs + 双指针
    bool bfs_two_points(TreeNode* root)
    {
        queue<TreeNode*> Q;
        Q.push(root);
        Q.push(root);
        while (!Q.empty()) {
            int size = Q.size();
            for (int i = 0; i < size; i = i + 2) {
                TreeNode* left = Q.front();
                Q.pop();
                TreeNode* right = Q.front();
                Q.pop();
                // 关键点，要跳过空子节点，否则会无限循环
                if (!left && !right) continue;
                if ((!left || !right) || left->val != right->val) return false;

                Q.push(left->left);
                Q.push(right->right);

                Q.push(left->right);
                Q.push(right->left);
            }
        }
        return true;
    }

    // dfs + 双指针
    bool dfs_two_points(TreeNode* left, TreeNode* right)
    {
        if (!left && !right) {
            return true;
        }

        if (!left || !right) {
            return false;
        }

        return left->val == right->val && dfs_two_points(left->left, right->right) &&
               dfs_two_points(left->right, right->left);
    }
};
// @lc code=end
