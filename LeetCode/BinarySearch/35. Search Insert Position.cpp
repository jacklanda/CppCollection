/* time complexity: O(log(n)) */
/* space complexity: O(1) */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (target == nums[mid]) return mid;
            else if (target > nums[mid]) left = mid + 1;
            else if (target < nums[mid]) right = mid - 1;
        }
        return left;
    }
};
