/* Classic DP Approach */
/* time complexity: O(n) */
/* space complexity: O(n) */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> buy_prices(prices.size(), 0);
        vector<int> profits(prices.size(), 0);
        buy_prices[0] = prices[0];
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            profit = prices[i] - prices[i - 1];
            buy_prices[i] = std::min(buy_prices[i - 1], prices[i]);
            profits[i] = profit > 0 ? profits[i - 1] + profit : profits[i - 1];
        }
        return profits.back();
    }
};

/* Optimal Solution */
/* time complexity: O(n) */
/* space complexity: O(1) */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i - 1]) profit += prices[i] - prices[i - 1];
        }
        return profit;
    }
};
