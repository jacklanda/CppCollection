/* time complexity: O(log(n)) */
/* space complexity: O(1) */

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] == target) return true;
            
            if (nums[left] == nums[mid] and nums[right] == nums[mid]) {
                ++left;
                --right;
            } else if (nums[left] <= nums[mid]) {
                if (target >= nums[left] and target < nums[mid]) right = mid - 1;
                else left = mid + 1;
            } else if (nums[left] > nums[mid]) {
                if (target > nums[mid] and target <= nums[right]) left = mid + 1;
                else right = mid - 1;
            }
        }
        return false;
    }
};
