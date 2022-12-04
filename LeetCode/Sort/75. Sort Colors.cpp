class Solution {
public:
    void sortColors(vector<int>& nums) {
        int max_freq = 0;
        unordered_map<int, int> num2freq;
        for (const int& num : nums) {
            max_freq = std::max(max_freq, ++num2freq[num]);
        }

        vector<vector<int>> buckets(3);
        for (const auto& pair : num2freq) {
            for (int i = 0; i < pair.second; ++i) {
                if (pair.first == 0) {
                    buckets[0].emplace_back(pair.first);
                } else if (pair.first == 1) {
                    buckets[1].emplace_back(pair.first);
                } else if (pair.first == 2) {
                    buckets[2].emplace_back(pair.first);
                }
            }
        }

        nums.clear();
        for (int i = 0; i < 3; ++i) {
            for (const int& num : buckets[i]) nums.emplace_back(num);
        }
    }
};
