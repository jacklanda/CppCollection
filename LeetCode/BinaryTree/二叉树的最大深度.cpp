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

/* DFS */
/* 时间复杂度：O(n)
 * 空间复杂度：O(n) */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        return recursiveTraverse(root, 1);
    }
    int recursiveTraverse(TreeNode* root, int depth) {
        if (!root) return 0;
        int left_depth, right_depth;
        left_depth = recursiveTraverse(root->left, depth) + 1;
        right_depth = recursiveTraverse(root->right, depth) + 1;
        return max(left_depth, right_depth);
    }
};

/* BFS */
/* 时间复杂度: O(n) */
/* 空间复杂度: O(n) */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        vector<vector<int>> res;
        q.emplace(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> vec;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                vec.emplace_back(node->val);
                if (node->left) q.emplace(node->left);
                if (node->right) q.emplace(node->right);
            }
            res.emplace_back(vec);
        }
        return res.size();
    }
};
