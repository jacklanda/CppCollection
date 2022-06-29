/* Monotonic Stack */
/* time complexity: O(n) */
/* space complexity: O(n) */

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<int> stk;
        std::vector<int> res(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); ++i) {
            while (!stk.empty()) {
                int tmp = stk.top();
                if (temperatures[tmp] < temperatures[i]) {
                    stk.pop();
                    res[tmp] = i - tmp;
                } else {
                    break;
                }
            }
            stk.emplace(i);
        }
        return res;
    }
};
