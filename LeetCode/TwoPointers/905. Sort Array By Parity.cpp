/* In-place */
/* time complexity: O(n) */
/* space complexity: O(1) */

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            while (left < right and ((nums[left] & 0x1) == 0)) ++left;
            while (left < right and ((nums[right] & 0x1) == 1)) --right;
            std::swap(nums[left++], nums[right--]);
        }
        return nums;
    }
};
