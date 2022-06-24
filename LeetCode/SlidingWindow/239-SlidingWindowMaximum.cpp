/* using deque to simulate sliding window */
/* time complexity: O(n) */
/* space complexity: O(n) */

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::vector<int> res;
        std::deque<int> window;
        for (int i = 0; i < nums.size(); ++i) {
            if (!window.empty() and window.front() + k == i) window.pop_front();
            while (!window.empty() and nums[window.back()] < nums[i]) window.pop_back();
            window.emplace_back(i);
            if (i >= k - 1) res.emplace_back(nums[window.front()]);
        }
        return res;
    }
};
