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

/* 递归中序遍历二叉树
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 * */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        traverse(root);
        return res;
    }
    void traverse(TreeNode* root) {
        if (root == nullptr) return;
        traverse(root->left);
        res.emplace_back(root->val);
        traverse(root->right);
    }

private:
    vector<int> res;
};

/* 迭代中序遍历二叉树(用stack模拟栈帧) */
/* 时间复杂度: O(n) */
/* 空间复杂度: O(n) */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        while (cur != nullptr || !stk.empty()) {
            while (cur != nullptr) {
                stk.emplace(cur);
                cur = cur->left;
            }
            cur = stk.top();
            res.emplace_back(cur->val);
            stk.pop();
            cur = cur->right;
        }
        return res;
    }
};
