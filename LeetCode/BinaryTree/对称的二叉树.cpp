/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* 判断一颗二叉树是否左右对称(镜像) */
/* 时间复杂度: O(n) */
/* 空间复杂度: O(n) */
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
