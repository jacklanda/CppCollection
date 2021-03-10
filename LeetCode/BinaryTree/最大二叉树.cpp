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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return BuildTree(nums, 0, nums.size() - 1);
    }

    TreeNode* BuildTree(vector<int>& nums, int low, int high) {
        if (low > high) return nullptr;

        int index = low, max = nums[low];
        for (int i = low; i <= high; i++) {
            if (nums[i] < max) {
                continue;
            } else if (nums[i] > max) {
                max = nums[i];
                index = i;
            }
        }

        TreeNode* root = new TreeNode(max);

        root->left = BuildTree(nums, low, index - 1);
        root->right = BuildTree(nums, index + 1, high);

        return root;
    }
};
