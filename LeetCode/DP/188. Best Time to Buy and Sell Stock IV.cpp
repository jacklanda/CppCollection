/* time complexity: O(n) */
/* space complexity: O(n*(2*k+1)) */

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int max_profit = 0;
        vector<vector<int>> dp(prices.size(), vector<int>(2 * k + 1, 0));
        for (int j = 1; j < 2 * k + 1; ++j) {
            dp[0][j] = (j & 0x01) ? -prices[0] : 0;
        }
        for (int i = 1; i < prices.size(); ++i) {
            for (int j = 0; j < 2 * k + 1; ++j) {
                if (j == 0) {
                    dp[i][j] = dp[i - 1][j];
                } else if ((j & 0x01) == 1) {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
                } else if ((j & 0x01) == 0) {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - 1] + prices[i]);
                }
                max_profit = std::max(dp[i][j], max_profit);
            }
        }
        return max_profit;
    }
};
