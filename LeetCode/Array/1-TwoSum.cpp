/* time complexity: O(n) */
/* space complexity: O(n) */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> num2pos;
        for (int i = 0; i < nums.size(); ++i) {
            if (num2pos.find(target - nums[i]) == num2pos.end())
                num2pos[nums[i]] = i;
            else
                return {i, num2pos[target - nums[i]]};
        }
        return {};
    }
};
