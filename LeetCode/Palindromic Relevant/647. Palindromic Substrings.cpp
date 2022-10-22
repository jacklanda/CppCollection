/* time complexity: O(n^2) */
/* space complexity: O(1) */

class Solution {
public:
    int countSubstrings(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); ++i) {
            result += count(s, i, i);
            result += count(s, i, i + 1);
        }
        return result;
    }
    
    int count(string& s, int i, int j) {
        int result = 0;
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            i--;
            j++;
            result++;
        }
        return result;
    }
};
