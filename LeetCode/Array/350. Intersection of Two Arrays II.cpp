/* time complexity: O(n) */
/* space complexity: O(n) */

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_map<int, int> num2freq;
        std::vector<int> res;
        for (const int& num : nums1) {
            if (num2freq.count(num) == 0) num2freq[num] = 0;
            ++num2freq[num];
        }
        for (const int& num : nums2) {
            if (num2freq.count(num) > 0 and num2freq[num] > 0) {
                res.emplace_back(num);
                --num2freq[num];
            }
        }
        return res;
    }
};
