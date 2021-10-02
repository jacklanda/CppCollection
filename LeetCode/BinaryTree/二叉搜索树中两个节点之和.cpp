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

/* 时间复杂度: O(n) */
/* 空间复杂度: O(n) */
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (root == nullptr) return false;
        bool is_contain = s.count(root->val);
        s.insert(k - (root->val));
        return is_contain || findTarget(root->left, k) ||
               findTarget(root->right, k);
    }

private:
    std::unordered_set<int> s;
};
