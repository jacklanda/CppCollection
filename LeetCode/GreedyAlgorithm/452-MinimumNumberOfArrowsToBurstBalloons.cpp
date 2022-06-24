/* time complexity: O(knlogn) */
/* space complexity: O(logn) */

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        std::sort(points.begin(), points.end());
        int count = 1, prev_tail = points[0][1];
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] <= prev_tail) {
                prev_tail = std::min(points[i][1], prev_tail);
            } else {
                ++count;
                prev_tail = points[i][1];
            }
        }
        return count;
    }
};
