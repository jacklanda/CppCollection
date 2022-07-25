/* time complexity: O(n) */
/* space complexity: O(n) */

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        std::multiset<int> window(nums.begin(), nums.begin() + k);
        auto mid = std::next(window.begin(), k / 2);
        std::vector<double> medians;
        for (int i = k; ; ++i) {
            medians.emplace_back((double(*mid) + *std::prev(mid, 1 - k % 2)) / 2);
            
            if (i == nums.size())
                return medians;
            
            window.emplace(nums[i]);
            if (nums[i] < *mid)
                --mid;
            
            if (nums[i - k] <= *mid)
                ++mid;
            
            window.erase(window.lower_bound(nums[i - k]));
        }
    }
};
