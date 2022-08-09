/* time complexity: O(n) */
/* space complexity: O(1) */

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover = 0;
        
        for (int i = 0; i <= cover; ++i) {
            cover = std::max(i + nums[i], cover);
            if (cover >= nums.size() - 1) return true;
        }
        
        return false;
    }
};
