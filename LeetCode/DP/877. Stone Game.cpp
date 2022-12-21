/* DFS: TLE! */
/* time complexity: O(2^n) */
/* space complexity: O(n) */

class Solution {
private:
    int getScore(vector<int>& piles, int left, int right) {
        if (left == right)
            return piles[left];
        int select_left = piles[left] - getScore(piles, left + 1, right);
        int select_right = piles[right] - getScore(piles, left, right - 1);
        return std::max(select_left, select_right);
    }
public:
    bool stoneGame(vector<int>& piles) {
        return getScore(piles, 0, piles.size() - 1) >= 0;
    }
};

/* Game theory */
/* time complexity: O(1) */
/* space complexity: O(1) */

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};

/* DP Approach */
/* time complexity: O(n^2) */
/* space complexity: O(n) */
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int len = piles.size();
        vector<vector<int>> dp(len, vector<int>(len));
        for (int i = 0; i < len; ++i) dp[i][i] = piles[i];

        for (int i = len - 2; i >= 0; --i) {
            for (int j = i + 1; j < len; ++j) {
                dp[i][j] = std::max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
            }
        }

        return dp[0][len - 1] > 0;
    }
};
