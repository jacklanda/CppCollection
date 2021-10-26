/* 暴力法确定左右边界 */
/* 时间复杂度: O(n) */
/* 空间复杂度: O(1) */
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lbound{-1}, rbound{-1};
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target && lbound == -1) lbound = i;
            if (nums[i] == target && lbound != -1) rbound = i;
            if (lbound != -1 && rbound != -1 && nums[i] != target) break;
        }
        return {lbound, rbound};
    }
};

/* 二分查找确定左右边界 */
/* 时间复杂度: O(logn) */
/* 空间复杂度: O(1) */
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int lbound = -1, rbound = -1;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (nums[mid] == target) {
                lbound = rbound = mid;
                while (lbound - 1 >= low && nums[lbound - 1] == target) --lbound;
                while (rbound + 1 <= high && nums[rbound + 1] == target) ++rbound;
                break;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            }
        }
        return {lbound, rbound};
    }
};
