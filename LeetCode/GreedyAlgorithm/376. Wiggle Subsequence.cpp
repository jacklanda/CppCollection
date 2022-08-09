/* time complexity: O(n) */
/* space complexity: O(1) */

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int prev_diff = 0, curr_diff = 0, res = 1;
        
        for (int i = 0; i < nums.size() - 1; ++i) {
            curr_diff = nums[i + 1] - nums[i];
            if ((prev_diff <= 0 and curr_diff > 0) or (prev_diff >= 0 and curr_diff < 0)) {
                ++res;
                prev_diff = curr_diff;
            }
        }
        
        return res;
    }
};
