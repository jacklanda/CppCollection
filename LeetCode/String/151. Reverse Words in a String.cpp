/* time complexity: O(n) */
/* space complexity: O(1) */

class Solution {
private:
    void removeSpaces(string& s) {
        int idx = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ') {
                if (idx != 0) s[idx++] = ' ';
                while (i < s.size() && s[i] != ' ') s[idx++] = s[i++];
            }
        }
        s.resize(idx);
    }

    void reverseWordbyWord(string& s) {
        for (int i = 0, j = 0; j <= s.size(); ++j) {
            if (j == s.size() || s[j] == ' ') {
                std::reverse(s.begin() + i, s.begin() + j);
                i = j + 1;
            }
        }
    }
public:
    string reverseWords(string s) {
        removeSpaces(s);  // remove redundant space
        std::reverse(s.begin(), s.end());  // reverse the all string
        reverseWordbyWord(s);  // reverse word separated by a single space
        return s;
    }
};
