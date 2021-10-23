/* 暴力法 */
/* 时间复杂度: O(n) */
/* 空间复杂度: O(1) */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int res{0};
        for (const int& n : nums) {
            if (n == target) ++res;
        }
        return res;
    }
};

/* 增加对上一个元素的备份，提前结束迭代 */
/* 时间复杂度: O(n) */
/* 空间复杂度: O(1) */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int res{0}, last{0};
        for (const int& n : nums) {
            if (n == target) {
                ++res;
                last = n;
            } else if (last == target) {
                break;
            }
        }
        return res;
    }
};

/* 二分查找-确定左右边界问题 */
/* 时间复杂度: O(logn) */
/* 空间复杂度: O(1) */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int res = 0, low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (nums[mid] == target) {
                int lbound = mid, rbound = mid + 1;
                while (lbound >= low && nums[lbound--] == target) ++res;
                while (rbound <= high && nums[rbound++] == target) ++res;
                break;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else if (nums[mid] < target) {
                low = mid + 1;
            }
        }
        return res;
    }
};
