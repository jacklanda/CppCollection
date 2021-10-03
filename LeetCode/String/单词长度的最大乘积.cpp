/* 该题本质上是一个位运算问题 */
/* 时间复杂度: O(n^2) */
/* 空间复杂度: O(n) */
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int state[words.size()];
        for (int i = 0; i < words.size(); ++i) {
            state[i] = 0;
            for (int j = 0; j < words[i].size(); ++j) {
                state[i] |= (1 << (words[i][j] - 'a'));
            }
        }
        int result = 0;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                if ((state[i] & state[j]) == 0) {
                    int tmp = words[i].size() * words[j].size();
                    result = std::max(result, tmp);
                }
            }
        }
        return result;
    }
};
