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
