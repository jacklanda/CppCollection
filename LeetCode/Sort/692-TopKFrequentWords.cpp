/* time complexity: O(n*log(n)) */
/* space complexity: O(n) */

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        std::unordered_map<std::string, int> str2freq;
        for (const std::string& word : words) {
            if (str2freq.find(word) == str2freq.end()) str2freq[word] = 0;
            ++str2freq[word];
        }

        std::vector<std::pair<std::string, int>> str2freq_array;
        for (const auto& pair : str2freq) str2freq_array.emplace_back(pair);
        std::sort(str2freq_array.begin(), str2freq_array.end(), [](auto& p1, auto& p2) {
            if (p1.second > p2.second or (p1.second == p2.second and p1.first < p2.first)) return true;
            return false;
        });

        std::vector<std::string> res;
        for (int i = 0; i < k; ++i) res.emplace_back(str2freq_array[i].first);

        return res;
    }
};
