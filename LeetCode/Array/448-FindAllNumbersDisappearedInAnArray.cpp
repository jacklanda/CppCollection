/* time complexity: O(n) */
/* space complexity: O(n) */

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for (const int& num : nums) {
            int idx = std::abs(num) - 1;
            if (nums[idx] > 0) nums[idx] = -nums[idx];
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) res.emplace_back(i + 1);
        }
        return res;
    }
};

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
