/* time complexity: O(n) */
/* space complexity: O(n) */

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int> stk;
        unordered_map<int, int> num2num;
        for (int i = 0; i < nums.size(); ++i) {
            while (stk.size() and stk.top() < nums[i]) {
                num2num[stk.top()] = nums[i];
                stk.pop();
            }
            stk.emplace(nums[i]);
        }
        
        vector<int> res;
        for (int n : findNums)
            res.emplace_back(num2num.count(n) ? num2num[n] : -1);
        
        return res;
    }
};
