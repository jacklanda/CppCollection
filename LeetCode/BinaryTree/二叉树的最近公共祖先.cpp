/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* 时间复杂度：O(n)
 * 空间复杂度：O(n) => 递归调用栈空间 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        if (root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        // 如果left和right都在以root为根的树中，那么直接返回root
        if (left && right) return root;
        // 如果left和right都不在以root为根的树中，则返回空指针
        if (!left && !right) return nullptr;
        // 如果left和right只有一个存在于以root为根的树中，则返回该存在的节点
        return left == nullptr ? right : left;
    }
};
