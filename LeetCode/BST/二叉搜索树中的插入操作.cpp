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

/* 节点参数是传值时的写法(原题) */
/* 时间复杂度: O(logn) */
/* 空间复杂度: O(logn) */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) return new TreeNode(val);
        if (root->val > val) root->left = insertIntoBST(root->left, val);
        if (root->val < val) root->right = insertIntoBST(root->right, val);
        return root;
    }
};

/* 节点参数是传引用时的写法 */
/* 时间复杂度: O(logn) */
/* 空间复杂度: O(logn) */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode*& root, int val) {
        if (root == nullptr) root = new TreeNode(val);
        if (root->val > val) insertIntoBST(root->left, val);
        if (root->val < val) insertIntoBST(root->right, val);
        return root;
    }
};
