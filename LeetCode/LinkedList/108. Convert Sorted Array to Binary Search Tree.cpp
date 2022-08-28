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
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build_tree(nums, 0, nums.size());
    }
    
    TreeNode* build_tree(vector<int>& nums, int left, int right) {
        if (left == right) return nullptr;
        int mid = left + ((right - left) >> 1);
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = build_tree(nums, left, mid);
        root->right = build_tree(nums, mid + 1, right);
        return root;
    }
};
