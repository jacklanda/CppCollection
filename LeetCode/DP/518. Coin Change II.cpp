/* time complexity: O(n^2) */
/* space complexity: O(n) */

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < coins.size(); ++i) {  // iterate items
            for (int backpack = coins[i]; backpack <= amount; ++backpack) {  // iterate backpacks
                dp[backpack] += dp[backpack - coins[i]];
            }
        }
        return dp[amount];
    }
};
