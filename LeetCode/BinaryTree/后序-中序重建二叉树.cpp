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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return recursiveBuild(inorder, 0, inorder.size() - 1, postorder, 0,
                              postorder.size() - 1);
    }

    TreeNode* recursiveBuild(vector<int>& inorder, int in_start, int in_end,
                             vector<int>& postorder, int post_start,
                             int post_end) {
        if (in_start > in_end) return nullptr;
        int index = 0;
        for (int i = in_start; i <= in_end; i++) {
            if (inorder[i] == postorder[post_end]) {
                index = i;
                break;
            }
        }

        int left_size = index - in_start;
        TreeNode* root = new TreeNode(postorder[post_end]);
        root->left = recursiveBuild(inorder, in_start, index - 1, postorder,
                                    post_start, post_start + left_size - 1);
        root->right = recursiveBuild(inorder, index + 1, in_end, postorder,
                                     post_start + left_size, post_end - 1);
        return root;
    }
};
