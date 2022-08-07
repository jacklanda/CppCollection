/* time complexity: O(n) */
/* space complexity: O(n) */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        std::vector<int> nums_copy = nums;
        for (int i = 0; i < nums.size(); ++i)
            nums[(i + k) % nums.size()] = nums_copy[i];
    }
};

/* In-place approach */
/* time complexity: O(n) */
/* space complexity: O(1) */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // k = k % nums.size();
        // [1, 2, 3, 4, 5, 6, 7]
        // ↓ ---> std::reverse(nums.begin(), nums.end());
        // [7, 6, 5, 4, 3, 2, 1]
        // ↓ ---> std::reverse(nums.begin(), nums.begin() + k);
        // [5, 6, 7, 4, 3, 2, 1]
        // ↓ ---> std::reverse(nums.begin() + k, nums.end());
        // [5, 6, 7, 1, 2, 3, 4]
        k = k % nums.size();
        std::reverse(nums.begin(), nums.end());
        std::reverse(nums.begin(), nums.begin() + k);
        std::reverse(nums.begin() + k, nums.end());
    }
};
