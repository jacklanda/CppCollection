/* time complexity: O(n) */
/* space complexity: O(n) */

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end(), [](int a, int b) { return std::abs(a) > std::abs(b); });
        for (int& num : nums) {
            if (num < 0 and k > 0) {
                num *= -1;
                --k;
            }
        }
        if (k & 0x01) nums.back() *= -1;
        
        return std::accumulate(nums.begin(), nums.end(), 0);
    }
};
