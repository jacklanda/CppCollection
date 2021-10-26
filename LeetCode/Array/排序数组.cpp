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

/* 非比较排序 - 计数排序 */
/* 在小范围内长度的数组使用计数排序效率较高 */
/* 时间复杂度: O(n+k) => 其中 n 是数组的元素个数，k 是数组中最大的值 */
/* 空间复杂度: O(n+k) */
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> res;
        res.reserve(nums.size());
        int hash_array[100001] = {0};
        for (const int& n : nums) {
            hash_array[n + 50000]++;
        }
        for (int i = 0; i < 100001; ++i) {
            while (hash_array[i] > 0) {
                --hash_array[i];
                res.push_back(i - 50000);
            }
        }
        return res;
    }
};
