/* time complexity: O(knlogn) */
/* space complexity: O(logn) */

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });
        int removed = 0, prev_tail = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < prev_tail)
                ++removed;
            else
                prev_tail = intervals[i][1];
        }
        return removed;
    }
};
