/* Bucket Sort */
/* time complexity: O(n) */
/* space complexity: O(n) */

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num2freq;
        int max_freq = 0;
        for (const int& num : nums) {
            max_freq = std::max(max_freq, ++num2freq[num]);
        }
        
        vector<vector<int>> buckets(max_freq+1);
        for (const auto& pair : num2freq) {
            buckets[pair.second].emplace_back(pair.first);
        }
        
        vector<int> res;
        for (int i = max_freq; i >= 0 && res.size() < k; --i) {
            for (const int& num : buckets[i]) {
                res.emplace_back(num);
                if(res.size() == k) break;
            }
        }
        
        return res;
    }
};
