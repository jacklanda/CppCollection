/* time complexity: O(n) */
/* space complexity: O(1) */

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (((mid & 0x01) == 0 and nums[mid] == nums[mid + 1]) or ((mid & 0x01) == 1 and nums[mid] == nums[mid - 1]))
                left = mid + 1;
            else
                right = mid;
        }
        
        return nums[left];
    }
};
