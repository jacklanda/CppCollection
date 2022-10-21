/* time complexity: O(n) */
/* space complexity: O(k) */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int max_len = 0, start = -1;
        for (int i = 0; i < s.size(); ++i) {
            start = std::max(dict[s[i]], start);
            dict[s[i]] = i;
            max_len = std::max(max_len, i - start);
        }
        return max_len;
    }
};
