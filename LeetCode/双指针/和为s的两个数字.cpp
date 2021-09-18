/* 双指针法 */
/* 时间复杂度: O(n) */
/* 空间复杂度: O(1) */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            if (nums[low] == target - nums[high])
                return {nums[low], nums[high]};
            else if (nums[low] < target - nums[high])
                ++low;
            else if (nums[low] > target - nums[high])
                --high;
        }
        return {};
    }
};
