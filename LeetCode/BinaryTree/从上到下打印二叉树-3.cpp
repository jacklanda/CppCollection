/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* 基于从上到下打印二叉树-2的修改
 * 最后对奇数下标的子数组进行逆序即可 */
/* 时间复杂度: O(n) */
/* 空间复杂度: O(n) */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> res;
        dfs(root, res, 0);
        for (int i = 0; i < res.size(); ++i) {
            if (i % 2 != 0) std::reverse(res[i].begin(), res[i].end());
        }
        return res;
    }
    void dfs(TreeNode* root, std::vector<std::vector<int>>& vec, int level) {
        if (root == nullptr) return;
        if (vec.size() <= level)
            vec.resize(level + 1);  // level 表示遍历到第几层
        vec[level].emplace_back(root->val);
        dfs(root->left, vec, level + 1);
        dfs(root->right, vec, level + 1);
    }
};

