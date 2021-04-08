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

/* 时间复杂度：O(n)
 * 空间复杂度：O(n) */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        return recursiveTraverse(root, 1);
    }
    int recursiveTraverse(TreeNode* root, int depth) {
        if (!root) return 0;
        int left_depth, right_depth;
        left_depth = recursiveTraverse(root->left, depth) + 1;
        right_depth = recursiveTraverse(root->right, depth) + 1;
        return max(left_depth, right_depth);
    }
};
