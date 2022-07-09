/* time complexity: O(n*log(n)) */
/* space complexity: O(n) */

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        std::map<int, int> num2freq;
        std::vector<int> res;

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums[i].size(); ++j) {
                if (num2freq.count(nums[i][j]) == 0) num2freq[nums[i][j]] = 0;
                ++num2freq[nums[i][j]];
            }
        }
        for (auto& item : num2freq) {
            if (item.second == nums.size()) res.emplace_back(item.first);
        }

        return res;
    }
};
