/* time complexity: O(n) */
/* space complexity: O(n) */

class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        stack<int> stk;
        for (int i = 0, start = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                stk.emplace(i);
            } else if (s[i] == ')' && !stk.empty()) {
                stk.pop();
                if (stk.empty()) res = std::max(res, i - start + 1);
                else res = std::max(res, i - stk.top());
            } else if (s[i] == ')' && stk.empty()) {
                start = i + 1;
            }
        }
        return res;
    }
};
