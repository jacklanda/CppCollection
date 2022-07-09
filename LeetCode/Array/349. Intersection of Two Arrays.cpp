/* time complexity: O(n) */
/* space complexity: O(n) */

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_set<int> record(nums1.begin(), nums1.end());
        std::vector<int> res;
        for (const int& num : nums2) {
            if (record.count(num) > 0) {
                res.emplace_back(num);
                record.erase(num);
            }
        }
        return res;
    }
};
