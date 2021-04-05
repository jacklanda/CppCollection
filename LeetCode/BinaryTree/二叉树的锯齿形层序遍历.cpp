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
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> vec;
        if (!root) return vec;
        queue<TreeNode*> node_queue;
        node_queue.push(root);
        bool reverse = true;
        while (!node_queue.empty()) {
            deque<int> level_list;
            int size = node_queue.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = node_queue.front();
                node_queue.pop();
                if (reverse)
                    level_list.push_back(node->val);
                else
                    level_list.push_front(node->val);
                if (node->left) node_queue.push(node->left);
                if (node->right) node_queue.push(node->right);
            }
            vec.emplace_back(vector<int>{level_list.begin(), level_list.end()});
            reverse = !reverse;
        }
        return vec;
    }
};

