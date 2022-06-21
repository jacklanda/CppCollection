/* time complexity: O(nlogn) */
/* space complexity: O(n) */

class MedianFinder {
private:
    std::priority_queue<int> max_queue;  // max heap for the first half data
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_queue;  // min heap for the second half data
public:
    MedianFinder() {}

    void addNum(int num) {
        if (max_queue.empty() or max_queue.top() > num)
            max_queue.emplace(num);
        else
            min_queue.emplace(num);

        // rebalance the two halfs to make sure the length difference is no larger than 1
        if (max_queue.size() > min_queue.size() + 1) {
            min_queue.emplace(max_queue.top());
            max_queue.pop();
        } else if (min_queue.size() > max_queue.size() + 1) {
            max_queue.emplace(min_queue.top());
            min_queue.pop();
        }
    }

    // return the median of data stream
    double findMedian() {
        if (max_queue.size() == min_queue.size())
            return max_queue.empty() ? 0.0 : (max_queue.top() + min_queue.top()) / 2.0;
        else
            return max_queue.size() > min_queue.size() ? max_queue.top() : min_queue.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
