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
    vector<int> levelOrder(TreeNode* root) {
        vector<int> vec;
        if (!root) return vec;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            TreeNode* node = q.front();
            vec.push_back(node->val);
            q.pop();
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        return vec;
    }
};
