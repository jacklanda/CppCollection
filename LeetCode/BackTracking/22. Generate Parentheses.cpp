/* time complexity: O(C(2n, n)) */
/* space complexity: O(log(n)) */

class Solution {
private:
    vector<string> res;
public:
    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0, "");
        return res;
    }

    void dfs(int n, int lc, int rc, string s) {
        if (lc == n && rc == n) res.emplace_back(s);
        if (lc < n) dfs(n, lc + 1, rc, s + "(");
        if (rc < lc) dfs(n, lc, rc + 1, s + ")");
    }
};
