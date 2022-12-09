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


/* Memorized search using map */
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

/* DP on Binary Tree */
/* time complexity: O(n) */
/* space complexity: O(log(n)) */
class Solution {
private:
    vector<int> robTree(TreeNode* root) {
        if (root == nullptr)
            return vector<int>{0, 0};
        vector<int> left_res = robTree(root->left);
        vector<int> right_res = robTree(root->right);
        int res1 = root->val + left_res[0] + right_res[0];  // steal current node
        int res2 = std::max(left_res[0], left_res[1]) + std::max(right_res[0], right_res[1]);  // non-steal current node
        return {res2, res1};
    }
public:
    int rob(TreeNode* root) {
        vector<int> res = robTree(root);
        return std::max(res[0], res[1]);
    }
};
