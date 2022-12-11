/* time complexity: O(n) */
/* space complexity: O(n) */

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        vector<int> dp_max(nums.size(), 0);
        vector<int> dp_min(nums.size(), 0);
        dp_max[0] = dp_min[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            dp_max[i] = std::max({nums[i], dp_max[i - 1] * nums[i], dp_min[i - 1] * nums[i]});
            dp_min[i] = std::min({nums[i], dp_min[i - 1] * nums[i], dp_max[i - 1] * nums[i]});
            res = std::max(dp_max[i], res);
        }
        /*
        std::for_each(dp_max.begin(), dp_max.end(), [](int num){ std::cout << num << ','; });
        std::cout << '\n';
        std::for_each(dp_min.begin(), dp_min.end(), [](int num){ std::cout << num << ','; });
        std::cout << '\n';
        */
        return res;
    }
};
