/* 使用单调栈即可 */
/* 时间复杂度: O(n) */
/* 空间复杂度: O(n) */
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<int> stk;
        std::vector<int> result(temperatures.size());
        for (int i = 0; i < temperatures.size(); ++i) {
            while (!stk.empty()) {
                int tmp = stk.top();
                if (temperatures[tmp] < temperatures[i]) {
                    stk.pop();
                    result[tmp] = i - tmp;
                } else {
                    break;
                }
            }
            stk.push(i);
        }
        return result;
    }
};
