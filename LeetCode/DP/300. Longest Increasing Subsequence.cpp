/* time complexity: O(n^2) */
/* space complexity: O(n) */

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int result = 1;
        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) dp[i] = std::max(dp[i], dp[j] + 1);
                result = std::max(dp[i], result);
            }
        }
        return result;
    }
};
