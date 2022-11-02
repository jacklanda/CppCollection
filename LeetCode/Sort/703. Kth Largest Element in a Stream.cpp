/* time complexity: O(k*log(k)) */
/* space complexity: O(k) */

class KthLargest {
private:
    int size;
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
public:
    KthLargest(int k, vector<int>& nums) {
        size = k;
        for (int& num : nums) {
            min_heap.emplace(num);
            if (min_heap.size() > size) min_heap.pop();
        }
    }
    
    int add(int val) {
        min_heap.emplace(val);
        if (min_heap.size() > size) min_heap.pop();
        return min_heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
