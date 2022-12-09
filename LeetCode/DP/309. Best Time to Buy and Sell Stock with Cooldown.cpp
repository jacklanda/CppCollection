/* time complexity: O(n) */
/* space complexity: O(n) */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(prices.size(), vector<int>(4, 0));
        // initialize dp table.
        dp[0][0] = -prices[0], dp[0][1] = dp[0][2] = dp[0][3] = 0;
        for (int i = 1; i < n; ++i) {
            dp[i][0] = std::max({dp[i - 1][0], dp[i - 1][2] - prices[i], dp[i - 1][3] - prices[i]});
            dp[i][1] = dp[i - 1][0] + prices[i];
            dp[i][2] = std::max(dp[i - 1][2], dp[i - 1][3]);
            dp[i][3] = dp[i - 1][1];
        }
        return std::max({dp[n - 1][1], dp[n - 1][2], dp[n - 1][3]});
    }
};
