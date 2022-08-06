/* time complexity: O(n)  */
/* space complexity: O(1) */

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        for (int i = 0, j = 1; i < nums.size(); i += 2, j += 2) {
            while (i < nums.size() and (nums[i] & 0x01) == 0) i += 2;
            while (j < nums.size() and (nums[j] & 0x01) == 1) j += 2;
            if (i < nums.size()) std::swap(nums[i], nums[j]);
        }
        return nums;
    }
};
