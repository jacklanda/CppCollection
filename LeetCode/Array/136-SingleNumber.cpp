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
