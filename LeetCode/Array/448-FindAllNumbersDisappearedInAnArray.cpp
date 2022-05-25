/* time complexity: O(n) */
/* space complexity: O(n) */

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        vector<int> buckets(nums.size() + 1, 0);
        for (const int& num : nums) ++buckets[num];
        for (int i = 1; i < buckets.size(); ++i)
            if (buckets[i] == 0) res.emplace_back(i);
        return res;
    }
};
