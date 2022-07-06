/* time complexity: O(n*log(n)) */
/* space complexity: O(n) */

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        std::vector<std::pair<int, int>> vec;
        for (const auto& trip : trips) {
            vec.push_back({trip[1], trip[0]});
            vec.push_back({trip[2], -trip[0]});
        }
        std::sort(vec.begin(), vec.end());

        int filled = 0;
        for (const auto& pair : vec) {
            filled += pair.second;
            if (filled > capacity) return false;
        }

        return true;
    }
};
