/* Math */
/* time complexity: O(n) */
/* space complexity: O(1) */

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        const int n = nums.size();
        return n * (n + 1) / 2 - std::accumulate(nums.begin(), nums.end(), 0);
    }
};

/* Bit Operation Approach */
/* time complexity: O(n) */
/* space complexity: O(1) */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i <= nums.size(); ++i) {
            if (i < nums.size()) res ^= nums[i];
            res ^= i;
        }
        return res;
    }
};
