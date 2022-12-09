/* time complexity: O(n) */
/* space complexity: O(n) */

class Solution {
private:
    int robRange(vector<int>& nums, int left, int right) {
        // 2 statuses, 0: steal, 1: non-steal
        vector<vector<int>> dp(nums.size(), vector<int>(2, 0));
        dp[left][0] = nums[left], dp[left][1] = 0;
        for (int i = left + 1; i <= right; ++i) {
            dp[i][0] = dp[i - 1][1] + nums[i];
            dp[i][1] = std::max(dp[i - 1][0], dp[i - 1][1]);
        }
        return std::max(dp[right][0], dp[right][1]);
    }
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int res1 = robRange(nums, 0, nums.size() - 2);
        int res2 = robRange(nums, 1, nums.size() - 1);
        return std::max(res1, res2);
    }
};
