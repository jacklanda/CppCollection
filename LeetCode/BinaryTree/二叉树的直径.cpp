/* 时间复杂度：O(n)
 * 空间复杂度：O(n) */
class Solution {
private:
    int max_depth;

public:
    int diameterOfBinaryTree(TreeNode* root) {
        get_depth(root);
        return max_depth - 1;
    }
    int get_depth(TreeNode* root) {
        if (!root) return 0;
        int ld = get_depth(root->left);
        int rd = get_depth(root->right);
        max_depth = max(max_depth, ld + rd + 1);
        return max(ld, rd) + 1;
    }
};

