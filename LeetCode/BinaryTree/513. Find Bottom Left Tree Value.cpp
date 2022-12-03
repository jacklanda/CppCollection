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

/* BFS */
/* time complexity: O(n) */
/* space complexity: O(n) */
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        vector<vector<int>> vec;
        queue<TreeNode*> q;
        q.emplace(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> sub_vec;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                sub_vec.emplace_back(node->val);
                if (node->left != nullptr) q.emplace(node->left);
                if (node->right != nullptr) q.emplace(node->right);
            }
            vec.emplace_back(sub_vec);
        }
        
        return vec.back()[0];
    }
};
