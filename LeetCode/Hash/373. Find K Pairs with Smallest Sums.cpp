/* Brute Force */
/* time complexity: O(m*n) */
/* space complexity: O(m+n) */

class Solution {
public:
    using sum2pair = std::pair<int, std::pair<int, int>>;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        std::vector<std::vector<int>> res;
        std::priority_queue<sum2pair, std::vector<sum2pair>, std::greater<sum2pair>> heap;

        for (int i = 0; i < nums1.size(); ++i) {
            for (int j = 0; j < nums2.size(); ++j) {
                heap.push({nums1[i] + nums2[j], {nums1[i], nums2[j]}});
            }
        }

        for (int i = k; i > 0; --i) {
            res.emplace_back(std::vector<int>{heap.top().second.first, heap.top().second.second});
            heap.pop();
            if (heap.empty()) break;
        }

        return res;
    }
};
