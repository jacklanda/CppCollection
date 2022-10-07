/* time complexity: O(n^2) */
/* space complexity: O(n) */

class Solution {
public:
    int integerBreak(int n) {
        std::vector<int> dp(n + 1, 0);
        dp[2] = 1;
        
        for (int i = 3; i <= n; ++i) {
            for (int j = 1; j < i - 1; ++j) {
                dp[i] = std::max({dp[i], (i - j) * j, dp[i - j] * j});
            }
        }
        
        return dp[n];
    }
};
