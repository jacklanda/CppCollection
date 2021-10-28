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
    int maxPathSum(TreeNode* root) {
        if (root == nullptr) return 0;
        dfs(root);
        return max_sum;
    }
    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;
        int left_sum = std::max(0, dfs(root->left));
        int right_sum = std::max(0, dfs(root->right));
        max_sum = std::max(max_sum, (root->val + left_sum + right_sum));
        return root->val + std::max(left_sum, right_sum);
    }

private:
    int max_sum = INT_MIN;
};
