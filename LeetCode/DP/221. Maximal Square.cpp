/* time complexity: O(m*n) */
/* space complexity: O(m*n) */

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int max_side_length = 0, m = matrix.size(), n = matrix[0].size();
        // dp matrix that we will be making
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
        
        // iterate over the matrix
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                // find the 1 in binary matrix
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = std::min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                    max_side_length = std::max(max_side_length, dp[i][j]);
                }
            }
        }
        
        return max_side_length * max_side_length;
    }
};
