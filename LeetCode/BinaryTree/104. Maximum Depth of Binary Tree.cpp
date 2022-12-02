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
/* time complexity: O(n) */
/* space complexity: O(n) */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        else if (root->left == nullptr && root->right == nullptr)
            return 1;
        return traverse(root, 1);
    }

    int traverse(TreeNode* root, int depth) {
        if (root == nullptr) return 0;
        int left_depth = traverse(root->left, depth) + 1;
        int right_depth = traverse(root->right, depth) + 1;
        return std::max(left_depth, right_depth);
    }
};

/* BFS */
/* time complexity: O(n) */
/* space complexity: O(n) */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        vector<vector<int>> vec;
        queue<TreeNode*> q;
        q.emplace(root);
        while (!q.empty()) {
            vector<int> sub_vec;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                sub_vec.emplace_back(node->val);
                if (node->left != nullptr) q.emplace(node->left);
                if (node->right != nullptr) q.emplace(node->right);
            }
            vec.emplace_back(sub_vec);
        }

        return vec.size();
    }
};
