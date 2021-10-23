/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/* BFS-二叉树的层序遍历 */
/* 时间复杂度: O(n) */
/* 空间复杂度: O(n) */
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        if (!root) return {};
        std::queue<TreeNode*> q;
        std::vector<int> res;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            res.emplace_back(node->val);
            q.pop();
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        return res;
    }
};
