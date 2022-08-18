/* time complexity: O(n) */
/* space complexity: O(1) */

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int char2pos[26] = {0};
        for (int i = 0; i < s.size(); ++i) char2pos[s[i] - 'a'] = i;

        vector<int> res;
        int left = 0, right = 0;
        for (int i = 0; i < s.size(); ++i) {
            right = std::max(right, char2pos[s[i] - 'a']);
            if (right == i) {
                res.emplace_back(right - left + 1);
                left = right + 1;
            }
        }

        return res;
    }
};
