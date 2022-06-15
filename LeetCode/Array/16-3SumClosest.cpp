/* time complexity: O(n^2) */
/* space complexity: O(1) */

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = 0, min_gap = INT_MAX;
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                int gap = std::abs(sum - target);
                if (gap < min_gap) {
                    res = sum;
                    min_gap = gap;
                }
                if (sum < target)
                    ++j;
                else
                    --k;
            }
        }
        return res;
    }
};
