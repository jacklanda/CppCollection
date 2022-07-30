/* time complexity: O(m*n) */
/* space complexity: O(m*n) */

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1')
                    dp[i][j] = (j == 0 ? 0 : dp[i][j - 1]) + 1;
            }
        }
        
        int res;
        std::stack<int> stk;
        for (int j = 0; j < n; ++j) {
            std::vector<int> vec(m + 2, 0);
            for (int i = 0; i < m; ++i)
                vec[i + 1] = dp[i][j];
            while (stk.size()) stk.pop();
            stk.emplace(0);
            for (int i = 1; i < vec.size(); ++i) {
                while (vec[stk.top()] > vec[i]) {
                    int h = vec[stk.top()];
                    stk.pop();
                    int w = i - stk.top() - 1;
                    res = std::max(res, w * h);
                }
                stk.emplace(i);
            }
        }
        
        return res;
    }
};
