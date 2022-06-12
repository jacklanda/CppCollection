/* time complexity: O(n) */
/* space complexity: O(n) */

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        std::vector<int> ans;
        std::unordered_map<int, int> num2freq;
        for (const int& num : nums) {
            if (num2freq.find(num) == num2freq.end()) num2freq[num] = 0;
            ++num2freq[num];
        }
        for (const std::pair<int, int>& pair : num2freq) {
            if (pair.second == 1) ans.emplace_back(pair.first);
        }
        return ans;
    }
};
