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
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        dfs(root, target);
        return result;
    }
    void dfs(TreeNode* root, int target) {
        if (!root) return;
        path.emplace_back(root->val);
        target -= root->val;
        if (!root->left && !root->right && target == 0)
            result.emplace_back(path);
        dfs(root->left, target);
        dfs(root->right, target);
        path.pop_back();
    }

private:
    vector<vector<int>> result;
    vector<int> path;
};
