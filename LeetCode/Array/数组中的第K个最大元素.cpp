/* 暴力法：
 * 对数组进行原地快排，
 * 排好后的倒数第k的元素就是
 * 数组中的第K个最大元素
 * 时间复杂度：O(nlogn) => 快排的平均时间复杂度，
 * 空间复杂度：O(1) => 数组的原地排序 */
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();
        sort(begin(nums), end(nums));
        return nums[size - k];
    }
};

/* 减治法：
 * 利用每一次快排可以确定一个元素
 * 在数组中的绝对位置的特性，且在每次
 * 调用partition函数进行切分后能缩小搜索的范围。
 * 通过这样“减而治之”的思想实现数组中的第K大元素的查找 */

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        int left = 0;
        int right = len - 1;

        // 第K大元素的索引是len - k
        int target = len - k;

        while (true) {
            int index = partition(nums, left, right);
            if (index == target)
                return nums[index];
            else if (index < target)
                left = index + 1;
            else if (index > target)
                right = index - 1;
        }
    }

    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        int j = left;
        for (int i = left + 1; i <= right; i++) {
            if (nums[i] < pivot) {
                j++;
                swap(nums, j, i);
            }
        }
        swap(nums, j, left);
        return j;
    }

    void swap(vector<int>& nums, int index1, int index2) {
        int temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
    }
};

/* 优先级队列 ——— 小顶堆
 * 维护一个容量为k的小顶堆，
 * 堆顶是第K个最大的数，
 * 本题可直接使用STL中的
 * priority_queue来实现相关算法。
 */
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto n : nums) {
            if (pq.size() == k && pq.top() >= n) continue;
            if (pq.size() == k) {
                pq.pop();
            }
            pq.push(n);
        }
        return pq.top();
    }
};
