/* time complexity: O(n) */
/* space complexity: O(1) */

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int idx = 0;
        for (int& num : nums) {
            // nums[idx++] = num; // is okay
            if (num != val) std::swap(num, nums[idx++]);
        }
        return idx;
    }
};
