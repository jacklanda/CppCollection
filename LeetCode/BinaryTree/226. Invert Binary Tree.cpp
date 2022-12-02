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

/* None-Recursively Traverse */
/* time complexity: O(n) */
/* space complexity: O(n) */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return root;

        queue<TreeNode*> q;
        q.emplace(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left != nullptr) q.emplace(node->left);
            if (node->right != nullptr) q.emplace(node->right);
            std::swap(node->left, node->right);
        }

        return root;
    }
};

/* Recursively Traverse */
/* time complexity: O(n) */
/* space complexity: O(n) */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return root;

        std::swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};
