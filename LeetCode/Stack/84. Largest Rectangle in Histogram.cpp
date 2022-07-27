/* time complexity: O(n) */
/* space complexity: O(n) */

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        std::stack<int> stk;
        heights.emplace_back(0);
        
        for (int i = 0; i < heights.size(); ++i) {
            while (!stk.empty() and heights[stk.top()] > heights[i]) {
                int height = heights[stk.top()];
                stk.pop();
                if (!stk.empty())
                    res = std::max(res, height * (i - stk.top() - 1));
                else
                    res = std::max(res, height * i);
            }
            stk.emplace(i);
        }
        
        return res;
    }
};
