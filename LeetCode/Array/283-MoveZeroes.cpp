/* time complexity: O(n) */
/* space complexity: O(1) */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i = 0, j = 0; i < nums.size(); ++i)
            if (nums[i] != 0) std::swap(nums[i], nums[j++]);
    }
};
