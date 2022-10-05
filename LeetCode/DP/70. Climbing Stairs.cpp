/* time complexity: O(n) */
/* space complexity: O(1) */

class Solution {
public:
    int climbStairs(int n) {
        int prev = 1, curr = 2;
        for (int i = 3; i <= n; ++i) {
            int next = prev + curr;
            prev = curr, curr = next;
        }
        return n == 1 ? 1 : curr;
    }
};
