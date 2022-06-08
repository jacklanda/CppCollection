/* time complexity: O(n) */
/* space complexity: O(n) */

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_map<int, int> num2pos;
        for (int i = 0; i < nums.size(); ++i) {
            if (num2pos.find(nums[i]) != num2pos.end()) {
                if (std::abs(num2pos[nums[i]] - i) <= k)
                    return true;
                else
                    num2pos[nums[i]] = i;
            } else {
                num2pos[nums[i]] = i;
            }
        }
        return false;
    }
};
