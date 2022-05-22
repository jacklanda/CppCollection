/* time complexity: O(knlogn) */
/* space complexity: O(logn) */

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        int child = 0, cookie = 0;
        while (child < g.size() && cookie < s.size()) {
            if (g[child] <= s[cookie]) ++child;
            ++cookie;
        }
        return child;
    }
};
