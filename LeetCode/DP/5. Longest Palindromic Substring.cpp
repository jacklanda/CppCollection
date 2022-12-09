/* DP approach */
/* time complexity: O(n^2) */
/* space complexity: O(n^2) */

class Solution {
public:
    string longestPalindrome(string s) {
        int left = 0, right = 0;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        for (int i = s.size() - 1; i >= 0; --i) {
            for (int j = i; j < s.size(); ++j) {
                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } else if (s[i] == s[j]) {
                    if (j - i <= 1) {
                        dp[i][j] = true;
                    } else if (dp[i + 1][j - 1]) {
                        dp[i][j] = true;
                    }
                }
                if (dp[i][j] && j - i > right - left) {
                    left = i, right = j;
                }
            }
        }
        return s.substr(left, right - left + 1);
    }
};
