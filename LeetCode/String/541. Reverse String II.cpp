/* time complexity: O(n) */
/* space complexity: O(1) */

class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += 2 * k) {
            if (i + k < s.size()) std::reverse(s.begin() + i, s.begin() + i + k);
            else std::reverse(s.begin() + i, s.end());
        } 
        return s;
    }
};
