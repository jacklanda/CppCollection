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
        int len = nums.size(), left = 0, right = len - 1;
        while (true) {
            int l = left, r = right;
            int idx = left;
            std::swap(nums[left], nums[idx]);
            while (l < r) {
                while (l < r && nums[r] >= nums[left]) --r;
                while (l < r && nums[l] <= nums[left]) ++l;
                std::swap(nums[l], nums[r]);
            }
            std::swap(nums[l], nums[left]);

            if (l == len - k)
                return nums[l];
            else if (l > len - k)
                right = l - 1;
            else
                left = l + 1;
        }
    }
};
