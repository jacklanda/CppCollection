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

/* Recursive DFS */
/* time complexity: O(n) */
/* space complexity: O(n) */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root, false);
    }
    int dfs(TreeNode* root, bool is_left) {
        if (root == nullptr)
            return 0;
        if (root->left == nullptr && root->right == nullptr)
            return is_left ? root->val : 0;
        return dfs(root->left, true) + dfs(root->right, false);
    }
};

/* Iterative DFS */
/* time complexity: O(n) */
/* space complexity: O(n) */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int sum = 0;
        stack<pair<TreeNode*, bool>> s;
        s.push({root, false});
        while (!s.empty()) {
            auto [node, is_left] = s.top();
            s.pop();
            if (node->left == nullptr && node->right == nullptr && is_left)
                sum += node->val;
            if (node->right != nullptr)
                s.push({node->right, false});
            if (node->left != nullptr)
                s.push({node->left, true});
        }

        return sum;
    }
};

/* BFS */
/* time complexity: O(n) */
/* space complexity: O(n) */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int sum = 0;
        queue<pair<TreeNode*, bool>> q;
        q.emplace(make_pair(root, false));
        while (!q.empty()) {
            auto [node, is_left] = q.front();
            q.pop();
            if (node->left == nullptr && node->right == nullptr && is_left)
                sum += node->val;
            if (node->left != nullptr) q.emplace(make_pair(node->left, true));
            if (node->right != nullptr) q.emplace(make_pair(node->right, false));
        }

        return sum;
    }
};
