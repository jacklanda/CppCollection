/* 调用sort库函数 */
/* 时间复杂度: O(nlogn) */
/* 空间复杂度: O(logn) */
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        std::sort(arr.begin(), arr.end());
        return vector<int>(arr.begin(), arr.begin() + k);
    }
};

/* 利用小根堆（优先级队列），依次弹出的k个数即为最小的k个数 */
/* 时间复杂度:
 * O(n)+k*O(logn)，通过数组一次性构造std::priority_queue为O(n)，单次插入/删除操作为O(logn)
 */
/* 空间复杂度:
 * O(n) */
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        std::priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());
        std::vector<int> vec;
        while (k--) {
            vec.emplace_back(pq.top());
            pq.pop();
        }
        return vec;
    }
};

/* 手动实现快排 */
/* 时间复杂度: O(nlogn) */
/* 空间复杂度: O(logn) */
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        quickSort(arr, 0, arr.size() - 1);
        return vector<int>(arr.begin(), arr.begin() + k);
    }
    void quickSort(vector<int>& arr, int low, int high) {
        if (high <= low) return;
        int midd = partition(arr, low, high);
        quickSort(arr, low, midd - 1);
        quickSort(arr, midd + 1, high);
    }
    int partition(vector<int>& arr, int low, int high) {
        int random_idx = low + rand() % (high - low + 1);
        std::swap(arr[low], arr[random_idx]);
        int pivot = arr[low];
        while (low < high) {
            while (low < high && arr[high] >= pivot) --high;
            arr[low] = arr[high];
            while (low < high && arr[low] <= pivot) ++low;
            arr[high] = arr[low];
        }
        std::swap(pivot, arr[low]);
        return low;
    }
};
