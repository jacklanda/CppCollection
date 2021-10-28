/* 时间复杂度: O(n) */
/* 空间复杂度: O(1) */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prev = 0, max_sum = nums[0];
        for (const int& n : nums) {
            prev = std::max(n, prev + n);
            max_sum = std::max(max_sum, prev);
        }
        return max_sum;
    }
};
