/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* M, N 分别是树A和树B的节点数量 */
/* 时间复杂度: O(MN) */
/* 空间复杂度: O(M) */
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        return (A != nullptr && B != nullptr && (traverse(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B)));
    }

private:
    bool traverse(TreeNode* A, TreeNode* B) {
        if (B == nullptr)
            return true;
        else if (A == nullptr || A->val != B->val)
            return false;
        return traverse(A->left, B->left) && traverse(A->right, B->right);
    }
};
