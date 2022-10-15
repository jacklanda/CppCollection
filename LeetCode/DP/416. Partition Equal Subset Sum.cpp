/* time complexity: O(n^2) */
/* space complexity: O(n) */

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        vector<int> dp(10001, 0);
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        
        if (sum & 0x01) return false;
        int target = sum / 2;
        
        // 0-1 back pack
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = target; j >= nums[i]; --j) {
                dp[j] = std::max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        
        return true ? target == dp[target] : false; 
    }
};
