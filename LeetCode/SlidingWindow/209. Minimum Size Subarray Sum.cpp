/* time complexity: O(n) */
/* space complexity: O(1) */

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0, sum = 0, length = INT_MAX;
        while (right < nums.size()) {
            sum += nums[right++];
            while (sum >= target) {
                sum -= nums[left++];
                length = std::min(length, right - left + 1);
            }
        }
        return length == INT_MAX ? 0 : length;
    }
};
