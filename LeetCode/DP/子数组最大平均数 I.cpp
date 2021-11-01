/* 经典的滑动窗口 */
/* 时间复杂度: O(n) */
/* 空间复杂度: O(1) */
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = std::accumulate(nums.begin(), nums.begin() + k, 0), max_sum = sum;
        for (int i = 1; i + k - 1 < nums.size(); ++i) {
            sum += nums[i + k - 1] - nums[i - 1];
            max_sum = std::max(sum, max_sum);
        }
        return static_cast<double>(max_sum) / k;
    }
};
