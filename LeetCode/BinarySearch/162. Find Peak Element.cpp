/* time complexity: O(log(n)) */
/* space complexity: O(1) */

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (mid + 1 <= right and nums[mid] < nums[mid + 1])
                left = mid + 1;
            else if (mid + 1 <= right and nums[mid] >= nums[mid + 1])
                right = mid;
            else
                break;
        }
        return left;
    }
};

/* time complexity: O(n) */
/* space complexity: O(1) */

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return std::distance(nums.begin(), std::max_element(nums.begin(), nums.end()));
    }
};
