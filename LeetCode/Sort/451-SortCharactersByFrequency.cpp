class Solution {
public:
    string frequencySort(string s) {
        int max_freq = 0;
        unordered_map<char, int> char2freq;
        for (char& c : s) {
            max_freq = std::max(max_freq, ++char2freq[c]);
        }

        vector<vector<char>> buckets(max_freq + 1);
        for (const auto& pair : char2freq) {
            int char_freq = pair.second;
            for (int i = 0; i < char_freq; ++i) buckets[char_freq].emplace_back(pair.first);
        }

        string res;
        for (int i = max_freq; i >= 0; --i) {
            for (const char& c : buckets[i]) {
                res.push_back(c);
            }
        }

        return res;
    }
};
