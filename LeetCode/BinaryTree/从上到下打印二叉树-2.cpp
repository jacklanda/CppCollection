/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vec;
        dfs(root, vec, 0);
        return vec;
    }
    void dfs(TreeNode* root, vector<vector<int>>& vec, int level) {
        if(root == NULL) return ;
        if(vec.size() <= level) vec.resize(level+1);    //level表示遍历到第几层
        vec[level].push_back(root->val);
        dfs(root->left, vec, level+1);
        dfs(root->right, vec, level+1);
    }
};
