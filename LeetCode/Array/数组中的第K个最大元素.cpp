/* 暴力法：
 * 调用库函数对数组进行原地快排，
 * 排好后的倒数第k的元素就是
 * 数组中的第K个最大元素
 * 时间复杂度：O(nlogn) => 快排的平均时间复杂度，
 * 空间复杂度：O(logn) => 数组的递归调用栈深度 */
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end(), [&](int x, int y) { return x > y; });
        return nums[k - 1];
    }
};

/* 多重集合 */
/* 时间复杂度: O(n) */
/* 空间复杂度: O(n) */
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::multiset<int, std::greater<int>> s(nums.begin(), nums.end());
        for (auto& n : s) {
            if (k == 1) return n;
            --k;
        }
        return INT_MAX;
    }
};

/* 优先级队列 ——— 小顶堆
 * 维护一个容量为k的小顶堆，
 * 堆顶是第K个最大的数，
 * 本题可直接使用STL中的
 * priority_queue来实现相关算法。
 * 时间复杂度: O(nlogn)
 * 空间复杂度: O(logn) => 堆排序递归调用栈空间的深度 */
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::less<int>> pq(nums.begin(), nums.end());
        while (--k) pq.pop();
        return pq.top();
    }
};

/* 减治法：
 * 利用每一次快排可以确定一个元素
 * 在数组中的绝对位置的特性，且在每次
 * 调用partition函数进行切分后能缩小搜索的范围。
 * 通过这样“减而治之”的思想实现数组中的第K大元素的查找
 * 时间复杂度: O(n)
 * 空间复杂度: O(logn) => 递归调用消耗的栈空间 */
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
