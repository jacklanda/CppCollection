/* 动态规划法 */
/* 时间复杂度: O(n) */
/* 空间复杂度: O(1) */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prev = 0, max_sum = nums[0];
        for (const auto& n : nums) {
            prev = max(prev + n, n);
            max_sum = max(prev, max_sum);
        }
        return max_sum;
    }
};

/* 贪心算法 */
/* 时间复杂度: O(n) */
/* 空间复杂度: O(1) */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, max_sum = INT_MIN;
        for (auto&& n : nums) {
            sum += n;
            max_sum = std::max(max_sum, sum);
            if (sum < 0) sum = 0;
        }
        return max_sum;
    }
};
