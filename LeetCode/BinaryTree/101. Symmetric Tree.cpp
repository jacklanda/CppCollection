/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* BFS */
/* time complexity: O(n) */
/* space complexity: O(n) */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;

        pair<TreeNode*, TreeNode*> node_pair;
        queue<pair<TreeNode*, TreeNode*>> q;
        q.emplace(make_pair(root->left, root->right));
        while (!q.empty()) {
            node_pair = q.front();
            q.pop();
            TreeNode* n1 = node_pair.first;
            TreeNode* n2 = node_pair.second;
            if (n1 == nullptr && n2 == nullptr)
                continue;
            else if (n1 == nullptr || n2 == nullptr || n1->val != n2->val)
                return false;
            q.emplace(make_pair(n1->left, n2->right));
            q.emplace(make_pair(n1->right, n2->left));
        }
        return true;
    }
};

/* DFS */
/* time complexity: O(n) */
/* space complexity: O(n) */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        else
            return isSubsymmetric(root->left, root->right);
    }
    bool isSubsymmetric(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr)
            return true;
        else if (left == nullptr || right == nullptr || left->val != right->val)
            return false;
        else
            return isSubsymmetric(left->left, right->right) && isSubsymmetric(left->right, right->left);
    }
};
