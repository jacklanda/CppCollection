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

/* Array-based Approach */
/* time complexity: O(n) */
/* space complexity: O(n) */

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> res(temperatures.size(), 0);
        for (int i = temperatures.size() - 2; i >= 0; --i) {
            int j = i + 1;  // start at next day
            while (j < temperatures.size() and temperatures[j] <= temperatures[i])
                j += res[j] ? res[j] : temperatures.size();  // iterate till you find next warmer day (NWD)
            // if j >= days' length, NWD doesnt exist. Otherwise, assign distance to NWD
            if (j < temperatures.size()) res[i] = j - i;
        }
        return res;
    }
};
