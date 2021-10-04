/* 使用双端队列模拟滑动窗口 */
/* 时间复杂度: O(n) */
/* 空间复杂度: O(n) */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::vector<int> result;
        std::deque<int> dq;
        for (int i = 0; i < nums.size(); ++i) {
            if (dq.front() + k == i) dq.pop_front();
            while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.emplace_back(i);
            if (i >= k - 1) result.emplace_back(nums[dq.front()]);
        }
        return result;
    }
};
