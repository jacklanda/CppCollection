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

/* DFS */
/* 时间复杂度: O(n) */
/* 空间复杂度: O(n) */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (root == nullptr) return 0;
        dfs(root, 0);
        return res;
    }
    void dfs(TreeNode* root, int num) {
        num = num * 10 + root->val;
        if (!root->left && !root->right) res += num;
        if (root->left) dfs(root->left, num);
        if (root->right) dfs(root->right, num);
    }

private:
    int res = 0;
};
