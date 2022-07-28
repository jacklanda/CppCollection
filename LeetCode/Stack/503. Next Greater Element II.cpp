/* time complexity: O(n) */
/* space complexity: O(n) */

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        const int size = nums.size();
        std::stack<int> stk;
        std::vector<int> res(size, -1);
        
        for (int i = 0; i < size * 2; ++i) {
            int num = nums[i % size];
            while (!stk.empty() and nums[stk.top()] < num) {
                res[stk.top()] = num;
                stk.pop();
            }
            if (i < size) stk.emplace(i);
        }
        
        return res;
    }
};
