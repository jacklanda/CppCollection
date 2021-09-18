/* 利用小根堆（优先级队列），依次弹出的k个数即为最小的k个数 */
/* 时间复杂度:
 * O(n)+k*O(logn)，通过数组一次性构造std::priority_queue为O(n)，单次插入/删除操作为O(logn)
 */
/* 空间复杂度:
 * O(n) */
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        std::priority_queue<int, vector<int>, greater<int>> pq(arr.begin(),
                                                               arr.end());
        std::vector<int> vec;
        while (k--) {
            vec.emplace_back(pq.top());
            pq.pop();
        }
        return vec;
    }
};
