/* time complexity: O(m*n) */
/* space complexity: O(m*n) */
/* m is the size of nums1, n is the size of nums2 */

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int result = 0;
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        for (int i = 1; i <= nums1.size(); ++i) {
            for (int j = 1; j <= nums2.size(); ++j) {
                if (nums1[i - 1] == nums2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                result = std::max(dp[i][j], result);
            }
        }
        return result;
    }
};
