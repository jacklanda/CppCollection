/* time complexity: O(n) */
/* space complexity: O(n) */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std::unordered_map<int, int> num2freq;
        for (const int& num : nums) {
            if (num2freq.find(num) == num2freq.end()) num2freq[num] = 0;
            ++num2freq[num];
        }
        for (const auto& item : num2freq) {
            if (item.second == 1) return item.first;
        }
        return -1;
    }
};
