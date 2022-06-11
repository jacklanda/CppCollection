/* time complexity: O(n) */
/* space complexity: O(1) */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum = 0;
        for (const int& num : nums) sum ^= num;
        return sum;
    }
};

/* time complexity: O(n) */
/* space complexity: O(1) */
class Solution {
public:
    int singleNumber(vector<int>& nums) { return std::accumulate(nums.begin(), nums.end(), 0, std::bit_xor<int>()); }
};
