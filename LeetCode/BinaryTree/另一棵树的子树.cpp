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

/* 时间复杂度: O(n) */
/* 空间复杂度: O(n) */
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr && subRoot != nullptr) return false;
        return dfs(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

private:
    bool dfs(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr && subRoot == nullptr)
            return true;
        else if (root == nullptr && subRoot != nullptr)
            return false;
        else if (root != nullptr && subRoot == nullptr)
            return false;
        else if (root->val != subRoot->val)
            return false;
        else
            return dfs(root->left, subRoot->left) && dfs(root->right, subRoot->right);
    }
};
