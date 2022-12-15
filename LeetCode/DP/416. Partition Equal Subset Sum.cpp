/* Classic DP Approach */
/* time complexity: O(n^2) */
/* space complexity: O(n) */

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum & 0x01) return false;  // edge case

        int volumn = sum / 2;
        vector<vector<int>> dp(nums.size(), vector<int>(volumn + 1, 0));
        for (int j = nums[0]; j <= volumn; ++j) dp[0][j] = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 1; j <= volumn; ++j) {
                if (j < nums[i]) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i]);
                if (dp[i][j] == volumn) return true;
            }
        }
        
        return false;
    }
};


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
