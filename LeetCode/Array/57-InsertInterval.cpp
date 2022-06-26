/* time complexity: O(n) */
/* space complexity: O(n) */

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        std::vector<std::vector<int>> res;
        for (int i = 0; i < intervals.size(); ++i) {
            if (intervals[i][1] < newInterval[0]) {
                // the new interval is after the range of other interval, so we can leave the current interval because the new one does not overlap
                // with it
                res.emplace_back(intervals[i]);
            } else if (intervals[i][0] > newInterval[1]) {
                // the new interval's range is before the current interval, so we can add the new interval and update it to the current one
                res.emplace_back(newInterval);
                newInterval = intervals[i];
            } else {
                // the new interval is in the range of the other interval, we have an overlap, so we must choose the min for start and max for end of
                // interval
                newInterval[0] = std::min(newInterval[0], intervals[i][0]);
                newInterval[1] = std::max(newInterval[1], intervals[i][1]);
            }
        }
        res.emplace_back(newInterval);
        return res;
    }
};
