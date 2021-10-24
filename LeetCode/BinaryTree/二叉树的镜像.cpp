/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* 递归遍历 */
/* 时间复杂度: O(n) */
/* 空间复杂度: O(n) */
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        traverse(root);
        return root;
    }

private:
    void traverse(TreeNode* root) {
        if (root == nullptr)
            return;
        else if (root->left == nullptr && root->right == nullptr)
            return;
        traverse(root->left);
        traverse(root->right);
        std::swap(root->left, root->right);
    }
};
