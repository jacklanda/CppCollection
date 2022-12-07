/* time complexity: O(n) */
/* space complexity: O(n) */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        vector<vector<int>> dp(prices.size(), vector<int>(5, 0));
        // initialize dp table.
        dp[0][0] = 0, dp[0][1] = -prices[0], dp[0][2] = 0, dp[0][3] = -prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            dp[i][2] = std::max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
            dp[i][3] = std::max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
            dp[i][4] = std::max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
            max_profit = std::max({dp[i][0], dp[i][1], dp[i][2], dp[i][3], dp[i][4], max_profit});
        }
        return max_profit;
    }
};
