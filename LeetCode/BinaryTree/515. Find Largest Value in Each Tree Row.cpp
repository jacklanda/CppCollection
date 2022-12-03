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

/* BFS with Sort */
/* time complexity: O(n*log(n)) */
/* space complexity: O(n) */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr)
            return {};
        
        vector<int> res;
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
        for (auto& v : vec) {
            std::sort(v.begin(), v.end());
            res.emplace_back(v.back());
        }
        
        return res;
    }
};

/* BFS without Sort */
/* time complexity: O(n) */
/* space complexity: O(n) */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr)
            return {};

        vector<int> res;
        vector<deque<int>> vec;
        queue<TreeNode*> q;
        q.emplace(root);
        while (!q.empty()) {
            int size = q.size();
            deque<int> dq;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if (!dq.empty() && node->val > dq.back())
                    dq.emplace_back(node->val);
                else if (!dq.empty() && node->val <= dq.back())
                    dq.emplace_front(node->val);
                else
                    dq.emplace_back(node->val);
                if (node->left != nullptr) q.emplace(node->left);
                if (node->right != nullptr) q.emplace(node->right);
            }
            vec.emplace_back(dq);
        }
        for (auto& dq : vec) {
            res.emplace_back(dq.back());
        }

        return res;
    }
};
