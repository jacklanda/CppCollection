/* time complexity: O(n) */
/* space complexity: O(k) */

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int char2char_s[128] = {}, char2char_t[128] = {};
        for (auto it_s = s.begin(), it_t = t.begin(); it_s != s.end(); ++it_s, ++it_t) {
            if (char2char_s[*it_s] == 0) char2char_s[*it_s] = *it_t;
            if (char2char_t[*it_t] == 0) char2char_t[*it_t] = *it_s;
            if (char2char_s[*it_s] != *it_t || char2char_t[*it_t] != *it_s) return false;
        }
        return true;
    }
};
