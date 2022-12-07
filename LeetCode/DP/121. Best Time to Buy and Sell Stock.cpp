/* Classic DP Approach */
/* time complexity: O(n) */
/* space complexity: O(n) */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        vector<int> buy_prices(prices.size(), 0);
        vector<int> profits(prices.size(), 0);
        buy_prices[0] = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            buy_prices[i] = std::min(buy_prices[i - 1], prices[i]);
            profits[i] = std::max(profits[i - 1], prices[i] - buy_prices[i]);
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
        int max_profit = 0;
        int min_buy_price = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            min_buy_price = std::min(min_buy_price, prices[i]);
            max_profit = std::max(max_profit, prices[i] - min_buy_price);
        }
        return max_profit;
    }
};
