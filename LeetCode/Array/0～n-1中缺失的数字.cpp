/* 时间复杂度: O(logn) */
/* 空间复杂度: O(1) */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (nums[mid] == mid)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
};
