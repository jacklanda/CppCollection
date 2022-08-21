/* time complexity: O(n) */
/* space complexity: O(1) */

class Solution {
public:
    string reverseWords(string s) {
        remove_extra_spaces(s);
        reverse(s, 0, s.size() - 1);
        for (int i = 0, j = 0; i <= s.size(); ++i) {
            if (s[i] == ' ' or i == s.size()) {
                reverse(s, j, i - 1);
                j = i + 1;
            }
        }
        return s;
    }
private:
    void remove_extra_spaces(string& s) {
        int slow = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ') {
                if (slow != 0) s[slow++] = ' ';
                while (s[i] != ' ' and i < s.size()) s[slow++] = s[i++];
            }
        }
        s.resize(slow);
    }
    
    void reverse(string& s, int left, int right) {
        while (left < right)
            std::swap(s[left++], s[right--]);
    }
};
