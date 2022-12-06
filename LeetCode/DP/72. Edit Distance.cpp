/* time complexity: O(n) */
/* space complexity: O(n) */

class Solution {
public:
    int minDistance(string word1, string word2) {
        // initialize dp table.
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for (int i = 0; i <= word1.size(); ++i) dp[i][0] = i;
        for (int j = 0; j <= word2.size(); ++j) dp[0][j] = j;
        for (int i = 1; i <= word1.size(); ++i) {
            for (int j = 1; j <= word2.size(); ++j) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = std::min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]}) + 1;
            }
        }
        return dp[word1.size()][word2.size()];
    }
};
