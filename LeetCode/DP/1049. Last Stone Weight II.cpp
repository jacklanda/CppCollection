/* time complexity: O(m*n) */
/* space complexity: O(m) */

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
