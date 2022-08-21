/* time complexity: O(n) */
/* space complexity: O(n) */

class Solution {
public:
    bool rotateString(string s, string goal) {
        return s.size() == goal.size() and (s + s).find(goal) != string::npos;
    }
};
