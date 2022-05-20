/* time complexity: O(n^2) */
/* space complexity: O(1) */

class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); ++i) {
            count += extend_substr(s, i, i);
            count += extend_substr(s, i, i + 1);
        }
        return count;
    }

    int extend_substr(string& s, int left, int right) {
        int count = 0;
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
            ++count;
        }
        return count;
    }
};
