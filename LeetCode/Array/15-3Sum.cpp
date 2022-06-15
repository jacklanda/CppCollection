/* time complexity: O(n^2) */
/* space complexity: O(1) */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        constexpr int target = 0;
        std::vector<std::vector<int>> res;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            int j = i + 1, k = nums.size() - 1;
            if (i >= 1 && nums[i] == nums[i - 1]) continue;  // dedup i
            while (j < k) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {  // dedup j
                    ++j;
                    continue;
                }
                if (k < nums.size() - 1 && nums[k] == nums[k + 1]) {  // dedup k
                    --k;
                    continue;
                }
                if (nums[i] + nums[j] + nums[k] > target)
                    --k;
                else if (nums[i] + nums[j] + nums[k] < target)
                    ++j;
                else if (nums[i] + nums[j] + nums[k] == target)
                    res.emplace_back(std::vector<int>{nums[i], nums[j++], nums[k]});
            }
        }
        return res;
    }
};
