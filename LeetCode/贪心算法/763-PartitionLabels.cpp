/* time complexity: O(n) */
/* space complexity: O(k) */

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int char2pos[128] = {};
        for (int i = 0; i < s.size(); ++i) char2pos[s[i]] = i;

        vector<int> res;
        int prev = -1, maximum = 0;

        for (int i = 0; i < s.size(); ++i) {
            maximum = std::max(maximum, char2pos[s[i]]);
            if (maximum == i) {
                res.emplace_back(maximum - prev);
                prev = maximum;
            }
        }
        return res;
    }
};
