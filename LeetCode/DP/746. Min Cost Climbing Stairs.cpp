/* time complexity: O(n) */
/* space complexity: O(n) */

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        std::vector<int> dp(cost.size());
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        for (int i = 2; i < cost.size(); ++i) {
            dp[i] = std::min(dp[i - 1], dp[i - 2]) + cost[i];
        }
        
        return std::min(dp[dp.size() - 1], dp[dp.size() - 2]);
    }
};

/* time complexity: O(n) */
/* space complexity: O(1) */

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev = cost[0], curr = cost[1];
        for (int i = 2; i < cost.size(); ++i) {
            int next = std::min(prev, curr) + cost[i];
            prev = curr, curr = next;
        }
        return std::min(prev, curr);
    }
};
