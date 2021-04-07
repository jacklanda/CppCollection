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

/* BFS：每层遍历的最后一个节点
 * 就是右视图能看见的节点 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> vec;
        if (!root) return vec;

        queue<TreeNode*> q;
        q.push(root);
        TreeNode* node;
        while (!q.empty()) {
            int queue_size = q.size();
            while (queue_size--) {
                node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            vec.push_back(node->val);
        }
        return vec;
    }
};
