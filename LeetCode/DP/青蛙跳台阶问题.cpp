/* 起点为1的斐波那契数列递推问题 */
/* 时间复杂度: O(n) */
/* 空间复杂度: O(1) */
class Solution {
public:
    int numWays(int n) {
        if (n == 0)
            return dp[0];
        else if (n == 1)
            return dp[1];
        while (n-- > 1) {
            dp[2] = (dp[0] + dp[1]) % 1000000007;
            dp[0] = dp[1];
            dp[1] = dp[2];
        }
        return dp[2];
    }

private:
    int dp[3] = {1, 1, 1};
};
