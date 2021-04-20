/* 基于快速排序实现的数组排序：
** 时间复杂度：O(nlogn) */
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
    void quickSort(vector<int>& nums, int low, int high) {
        if (low >= high) return;
        int mid = partition(nums, low, high);
        quickSort(nums, low, mid - 1);
        quickSort(nums, mid + 1, high);
    }
    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[low];
        while (low < high) {
            while (low < high && pivot <= nums[high]) high--;
            nums[low] = nums[high];
            while (low < high && pivot >= nums[low]) low++;
            nums[high] = nums[low];
        }
        nums[low] = pivot;
        return low;
    }
};
