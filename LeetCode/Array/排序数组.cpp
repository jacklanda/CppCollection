/* 基于快速排序实现的数组排序：
 * 时间复杂度: O(nlogn)
 * 空间复杂度: O(logn) => 递归调用的函数栈深度
 * NOTE: 如果为全部有序数组
 * 则时间复杂度将退化为 O(n^2) => 输入为大数组时容易超时!
 * 因此我们需要随机选取枢轴 */
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
        int random_index = low + rand() % (high - low + 1);  // 随机选取枢轴，避免输入为有序数组时造成的快排退化
        swap(nums[low], nums[random_index]);
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
