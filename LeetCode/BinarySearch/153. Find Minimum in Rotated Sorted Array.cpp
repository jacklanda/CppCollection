/* time complexity: O(log(n)) */
/* space complexity: O(1) */

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] < nums[right]) right = mid;
            else if (nums[mid] > nums[right]) left = mid + 1;
            else if (nums[mid] == nums[right]) return nums[mid];
        }
        return 0;
    }
};
