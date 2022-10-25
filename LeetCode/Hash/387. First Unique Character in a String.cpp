/* time complexity: O(n) */
/* space complexity: O(n) */

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> char2cnt(26, 0);
        for (char& c : s) char2cnt[c - 'a']++;
        for (int i = 0; i < s.size(); ++i) {
            if (char2cnt[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};
