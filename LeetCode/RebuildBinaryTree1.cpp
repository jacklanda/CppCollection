/* https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof/ */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return recursiveBuild(preorder, 0, preorder.size()-1,
                              inorder, 0, inorder.size()-1);
    }

    TreeNode* recursiveBuild(vector<int>& preorder, int pre_start, int pre_end,
                             vector<int>& inorder, int in_start, int in_end){
        if(pre_start > pre_end) return nullptr;
        int index = 0;
        for(int i=in_start; i<=in_end; i++){
            if(inorder[i] == preorder[pre_start]){
                index = i;
                break;
            }
        }

        int left_size = index - in_start;
        TreeNode* root = new TreeNode(preorder[pre_start]);
        root->left = recursiveBuild(preorder, pre_start+1, pre_start+left_size,
                                    inorder, in_start, index-1);
        root->right = recursiveBuild(preorder, pre_start+left_size+1, pre_end,
                                     inorder, index+1, in_end);
        return root;
    }
};
