/* time complexity: O(m*n) */
/* space complexity: O(m*n) */

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int max_val = 0;
        for (int i = 0; i < matrix.size(); ++i)
            for (int j = 0; j < matrix[i].size(); ++j)
                max_val = std::max(max_val, dfs(matrix, i, j, INT_MIN));
        return max_val;
    }
    
private:
    int dp[201][201];
    
    int dfs(vector<vector<int>>& matrix, int i, int j, int pre) {
        if (i < 0 or i >= matrix.size() or j < 0 or j >= matrix[0].size() or pre >= matrix[i][j])
            return 0;
        
        if (dp[i][j]) return dp[i][j];
        int left = dfs(matrix, i, j - 1, matrix[i][j]);
        int right = dfs(matrix, i, j + 1, matrix[i][j]);
        int up = dfs(matrix, i - 1, j, matrix[i][j]);
        int down = dfs(matrix, i + 1, j, matrix[i][j]);
        return dp[i][j] = 1 + std::max({left, right, up, down});
    }
};
