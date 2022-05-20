/* time complexity: O(n) */
/* space complexity: O(k) */
/* traverse strings three times totally using array as map */

class Solution {
public:
    bool isAnagram(string s, string t) {
        // int char2freq[128] = {};  // another variety of syntax
        int char2freq[128] = {0};
        for (char& c : s) ++char2freq[c];
        for (char& c : t)
            if (char2freq[c]-- == 0) return false;
        for (int& num : char2freq)
            if (num != 0) return false;
        return true;
    }
};
