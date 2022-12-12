/* time complexity: O(n^3) */
/* space complexity: O(n) */

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        unordered_set<string> word_set(wordDict.begin(), wordDict.end());
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {  // iterate bags(i.e. string s)
            for (int j = 0; j < i; ++j) {  // iterate items(i.e. word in word_set)
                string word = s.substr(j, i - j);
                if (dp[j] && word_set.find(word) != word_set.end()) {
                    dp[i] = true;
                }
            }
        }
        return dp.back();
    }
};
