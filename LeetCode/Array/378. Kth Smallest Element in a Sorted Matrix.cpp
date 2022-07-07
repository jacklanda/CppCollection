/* time complexity: O(n*log(n)) */
/* space complexity: O(log(n)) */

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> heap;
        for (const auto& row : matrix)
            for (const int& num : row) heap.emplace(num);
        for (int i = k; i > 1; --i) heap.pop();

        return heap.top();
    }
};
