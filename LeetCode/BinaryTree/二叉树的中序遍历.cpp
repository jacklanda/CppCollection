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

/* 简单地使用二叉树的
 * 递归框架思维即可解决问题
 * */
class Solution {
private:
    vector<int> vec;

public:
    vector<int> inorderTraversal(TreeNode* root) {
        assist_func(root);
        return vec;
    }
    void assist_func(TreeNode* root) {
        if (!root) return;
        assist_func(root->left);
        vec.push_back(root->val);
        assist_func(root->right);
    }
};
