/* time complexity: O(n) */
/* space complexity: O(n) */

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char& c : s) {
            if (c == '(') stk.emplace(')');
            else if (c == '[') stk.emplace(']');
            else if (c == '{') stk.emplace('}');
            else if (stk.empty()) return false;
            else if (c != stk.top()) return false;
            else if (c == stk.top()) stk.pop();
        }
        return stk.empty();
    }
};
