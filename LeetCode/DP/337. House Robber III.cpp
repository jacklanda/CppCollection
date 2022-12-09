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


/* time complexity: O(n) */
/* space complexity: O(log(n)) */

class Solution {
private:
    unordered_map<TreeNode*, int> node2sum;
public:
    int rob(TreeNode* root) {
        if (root == nullptr)
            return 0;
        if (root->left == nullptr && root->right == nullptr)
            return root->val;
        if (node2sum.find(root) != node2sum.end())
            return node2sum.at(root);
        // steal current node
        int sum1 = root->val;  
        if (root->left != nullptr)
            sum1 += rob(root->left->left) + rob(root->left->right);
        if (root->right != nullptr)
            sum1 += rob(root->right->left) + rob(root->right->right);
        // non-steal current node
        int sum2 = rob(root->left) + rob(root->right);
        node2sum[root] = std::max(sum1, sum2);
        return std::max(sum1, sum2);
    }
};
