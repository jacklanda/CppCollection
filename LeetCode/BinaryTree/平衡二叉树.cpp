/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        /* 当且仅当根节点的左子树平衡 && 右子树平衡 && 左右子树的深度不大于1时，
           才可判知该根节点为一棵平衡二叉树 */
        return isBalanced(root->left) && isBalanced(root->right) &&
               abs(nodeDepth(root->left) - nodeDepth(root->right)) <= 1;
    }
    /* 获取节点的最大深度 */
    int nodeDepth(TreeNode* root) {
        if (!root) return 0;
        int left_depth = nodeDepth(root->left);
        int right_depth = nodeDepth(root->right);
        if (left_depth > right_depth)
            return left_depth + 1;
        else if (left_depth <= right_depth)
            return right_depth + 1;
        return 1;
    }
};
