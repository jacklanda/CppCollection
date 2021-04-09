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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        assistFunc(root, ans);
        return ans;
    }
    void assistFunc(TreeNode* root, vector<int>& ans) {
        if (!root) return;
        assistFunc(root->left, ans);
        assistFunc(root->right, ans);
        ans.push_back(root->val);
        return;
    }
};
