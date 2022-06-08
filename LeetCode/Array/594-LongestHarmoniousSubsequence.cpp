/* time complexity: O(n) */
/* space complexity: O(n) */

class Solution {
public:
    int findLHS(vector<int>& nums) {
        std::unordered_map<int, int> num2freq;
        for (const int& num : nums) ++num2freq[num];

        int maximum = 0;
        for (auto [num, freq] : num2freq) {
            if (num2freq.find(num + 1) != num2freq.end()) maximum = std::max(maximum, freq + num2freq[num + 1]);
        }
        return maximum;
    }
};
