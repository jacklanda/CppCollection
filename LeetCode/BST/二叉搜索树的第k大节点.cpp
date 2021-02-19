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
    int result = 0;
    int kthLargest(TreeNode* root, int k) {
        inorder(root, k);
        return result;
    }
    void inorder(TreeNode* root, int &k){   //注意k是引用形式
        if(!root) return;

        inorder(root->right, k);        //中序倒序遍历，右-根-左，可以得到递减序列
        if(--k == 0){
            result = root->val;
            return;
        }
        inorder(root->left , k);
    }
};
