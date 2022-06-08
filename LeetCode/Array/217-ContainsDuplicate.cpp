/* time complexity: O(n) */
/* space complexity: O(n) */

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> set;
        for (const int& num : nums) {
            if (set.find(num) != set.end()) return true;
            set.emplace(num);
        }
        return false;
    }
};
