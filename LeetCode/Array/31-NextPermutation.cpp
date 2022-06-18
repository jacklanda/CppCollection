/* Library Function */
/* time complexity: O(n) */
/* space complexity: O(1) */

class Solution {
public:
    void nextPermutation(vector<int>& nums) { std::next_permutation(nums.begin(), nums.end()); }
};

/* Optimal Solution */
/* time complexity: O(n) */
/* space complexity: O(1) */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int l = 0, r = 0;
        for (l = nums.size() - 2; l >= 0; --l) {
            if (nums[l] < nums[l + 1]) break;
        }
        if (l < 0) {
            std::reverse(nums.begin(), nums.end());
        } else {
            for (r = nums.size() - 1; r > l; --r) {
                if (nums[r] > nums[l]) break;
            }
            std::swap(nums[r], nums[l]);
            std::reverse(nums.begin() + l + 1, nums.end());
        }
    }
};
