/* time complexity: O(n^2) */
/* space complexity: O(n) */

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size(), size2 = nums2.size();
        vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, -1e8));

        for (int i = 1; i <= size1; ++i) {
            for (int j = 1; j <= size2; ++j) {
                dp[i][j] = std::max({
                    nums1[i - 1] * nums2[j - 1], 
                    nums1[i - 1] * nums2[j - 1] + dp[i - 1][j - 1], 
                    dp[i][j - 1], 
                    dp[i - 1][j], 
                    dp[i - 1][j - 1]
                });
            }
        }
        return dp.back().back();
    }
};
