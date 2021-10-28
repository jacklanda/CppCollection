/* 时间复杂度: O(n) */
/* 空间复杂度: O(n) */
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int res{0};
        for (int pos = 0, start = 0; pos < s.size(); ++pos) {
            if (s[pos] == '(')
                stk.emplace(pos);
            else if (s[pos] == ')') {
                if (!stk.empty()) {
                    stk.pop();
                    if (stk.empty())
                        res = std::max(res, pos - start + 1);
                    else
                        res = std::max(res, pos - stk.top());  // pos - stk.top() + 1 - 1
                } else
                    start = pos + 1;
            }
        }
        return res;
    }
};
