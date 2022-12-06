/* Kadane's algorithm, Greedy algo */
/* time complexity: O(n) */
/* space complexity: O(1) */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, max_sum = INT_MIN;
        for (const int& num : nums) {
            sum = std::max(sum + num, num);
            max_sum = std::max(sum, max_sum);
        }
        return max_sum;
    }
};

/* DP approach */
/* time complexity: O(n) */
/* space complexity: O(n) */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        int res = dp[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = std::max(dp[i - 1] + nums[i], nums[i]);
            res = std::max(res, dp[i]);
        }
        return res;
    }
};
