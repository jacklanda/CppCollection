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

/* 解此题的基本思想是BSF
 * 即：广度优先搜索 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vec;
        if (!root) return vec;
        queue<TreeNode*> q;
        q.push(root);
        /* 每一次while遍历都代表着层序遍历中的一层
         * 也会在外层大的vector内压入一个新的vector元素 */
        while (!q.empty()) {
            vec.push_back(vector<int>());
            int element_num = q.size();
            for (int i = 0; i < element_num; i++) {
                TreeNode* node = q.front();
                q.pop();
                vec.back().push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return vec;
    }
};
