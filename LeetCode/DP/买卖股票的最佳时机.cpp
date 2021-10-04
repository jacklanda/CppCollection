/* 时间复杂度: O(n) */
/* 空间复杂度: O(1) */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0, min_price = INT_MAX;
        for (int& p : prices) {
            max_profit = std::max(max_profit, p - min_price);
            min_price = std::min(p, min_price);
        }
        return max_profit;
    }
};
