/* time complexity: O(n) */
/* space complexity: O(n) */

class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= s.size(); ++i) {
            if (s[i - 1] != '0') dp[i] = dp[i - 1];
            if (i >= 2) {
                int combination_int = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
                if (combination_int >= 10 && combination_int <= 26) dp[i] += dp[i - 2];
            }
        }
        return dp.back();
    }
};
