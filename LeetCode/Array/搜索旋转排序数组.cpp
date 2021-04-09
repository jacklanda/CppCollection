/* 应用二分搜索基本思想
 * 时间复杂度：O(logn)
 * 空间复杂度: O(1) */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (!nums.size()) return -1;
        if (nums.size() == 1) return nums[0] == target ? 0 : -1;

        int left = 0, right = nums.size() - 1, mid = 0;
        while (left <= right) {
            mid = (right - left) / 2 + left;
            if (nums[mid] == target) return mid;
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            } else {
                if (nums[mid] < target && target <= nums[nums.size() - 1])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
};
