/* time complexity: O(n) */
/* space complexity: O(n) */

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // 2 status
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] = -prices[0], dp[0][1] = 0;
        for (int i = 1; i < prices.size(); ++i) {
            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
        }
        return dp[prices.size() - 1][1];
    }
};
