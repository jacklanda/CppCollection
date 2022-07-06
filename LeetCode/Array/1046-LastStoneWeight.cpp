/* time complexity: O(n*log(n)) */
/* space complexity: O(n) */

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> heap(stones.begin(), stones.end());
        while (heap.size() > 1) {
            int s1 = heap.top();
            heap.pop();
            int s2 = heap.top();
            heap.pop();
            if (s1 > s2) heap.emplace(s1 - s2);
        }
        return heap.empty() ? 0 : heap.top();
    }
};
