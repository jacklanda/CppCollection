/* 简单的动态规划递推 */
/* 时间复杂度: O(n) */
/* 空间复杂度: O(1) */
class Solution {
public:
    int climbStairs(int n) {
        // f(n) = f(n-1) + f(n-2) ··· 斐波那契数列
        if (n == 1) return 1;
        int prev = 1, curr = 1;
        while (--n) {
            int temp = curr;
            curr += prev;
            prev = temp;
        }
        return curr;
    }
};
