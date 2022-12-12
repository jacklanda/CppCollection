/* time complexity: O(m*n) */
/* space complexity: O(m*n) */

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp.back().back();
    }
};

/* optimized space complexity solution */
/* time complexity: O(m*n) */
/* space complexity: O(n) */

class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<int> dp(n, 1);
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j)
                dp[j] += dp[j - 1];
        }
        return dp[n - 1];
    }
};
