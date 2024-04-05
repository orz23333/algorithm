/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */
#include <iostream>
#include <stdlib.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
        : val(0)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x)
        , left(left)
        , right(right)
    {
    }
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
// int INT_MAX = (2 << 31) - 1;
// int INT_MIN = 2 << 31;
long long MY_MIN_VALUE = LLONG_MIN;

class Solution {
public:
    bool isValidBST(TreeNode* root)
    {
        // return dfs(root, LLONG_MAX, LLONG_MIN);
        return dfs_math(root, MY_MIN_VALUE);
    }

    // 2024春节后再战！
    bool bfs(TreeNode* root) {

    }

    // dfs 利用二叉搜索树的特点
    bool dfs_math(TreeNode* root, long long& pre)
    {
        if (!root) {
            return true;
        }

        bool ans = true;

        if (root->left) {
            ans &= dfs_math(root->left, pre);
        }

        if (root->val > pre) {
            pre = root->val;
        } else {
            ans = false;
        }

        if (root->right) {
            ans &= dfs_math(root->right, pre);
        }

        return ans;
    }

    bool dfs(TreeNode* root, long long high, long long low)
    {
        if (!root) {
            return true;
        }

        if (root->val <= low || root->val >= high) {
            return false;
        }

        return dfs(root->left, root->val, low) && dfs(root->right, high, root->val);
    }

    long long MY_MIN_VALUE = LLONG_MIN;
};
// @lc code=end

int main()
{
    TreeNode root;
    root.val = 0;
    bool res = (Solution()).dfs_math(&root, MY_MIN_VALUE);
    cout << res << endl;
}
