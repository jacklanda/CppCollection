/* time complexity: O(m*n) */
/* space complexity: O(m*n) */

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = std::accumulate(stones.begin(), stones.end(), 0);
        int target = sum / 2;
        vector<vector<int>> dp(stones.size(), vector<int>(target + 1, 0));
        for (int j = stones[0]; j <= target; ++j) dp[0][j] = stones[0];

        for (int i = 1; i < stones.size(); ++i) {
            for (int j = 1; j <= target; ++j) {
                if (j < stones[i]) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - stones[i]] + stones[i]);
            }
        }

        return sum - 2 * dp.back().back();
    }
};

/* time complexity: O(m*n) */
/* space complexity: O(m*n) */

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        std::vector<int> dp(1501, 0);
        int sum = std::accumulate(stones.begin(), stones.end(), 0);
        int target = sum / 2;
        
        for (int i = 0; i < stones.size(); ++i) {
            for (int j = target; j >= stones[i]; --j) {
                dp[j] = std::max(dp[j], (dp[j - stones[i]]) + stones[i]);
            }
        }
        
        return (sum - dp[target]) - dp[target];
    }
};
