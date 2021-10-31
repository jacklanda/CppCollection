/* 时间复杂度: O(n) */
/* 空间复杂度: O(1) */
class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        int prev = 1, curr = 1;  // dp[-1] = dp[0] = 1
        for (int i = 1; i < s.size(); ++i) {
            int temp = curr;
            if (s[i] == '0') {
                if (s[i - 1] == '1' || s[i - 1] == '2')
                    curr = prev;
                else
                    return 0;  // 此时的 s[i] 跟它的前后位都无法结合，所以无法解码
            } else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6')) {
                curr += prev;
            }
            prev = temp;
        }
        return curr;
    }
};
