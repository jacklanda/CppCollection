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

/* DFS */
/* time complexity: O(n) */
/* space complexity: O(log(n)) */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) 
            return 0;
        if (root->left == NULL && root->right == NULL) // Reach to leaf node
            return 1; 
        if (root->left == NULL)  // only can choose right child
            return minDepth(root->right) + 1;
        if (root->right == NULL)   // only can choose left child
            return minDepth(root->left) + 1;
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};

/* BFS */
/* time complexity: O(n) */
/* space complexity: O(log(n)) */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int depth = 1;
        queue<TreeNode*> q;
        q.emplace(root);
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left == nullptr && node->right == nullptr)
                    return depth;
                if (node->left != nullptr)
                    q.emplace(node->left);
                if (node->right != nullptr)
                    q.emplace(node->right);
            }
            depth++;
        }

        return -1;
    }
};
