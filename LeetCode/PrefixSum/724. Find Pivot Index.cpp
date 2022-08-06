/* time complexity: O(n) */
/* space complexity: O(1) */

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0, partial_sum = 0; i < nums.size(); partial_sum += nums[i++])
            if (partial_sum * 2 == sum - nums[i]) return i;
        
        return -1;
    }
};
