/* time complexity: O(n) */
/* space complexity: O(n) */

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        std::vector<std::vector<int>> res;
        for (int i = 0; i < intervals.size(); ++i) {
            if (intervals[i][1] < newInterval[0]) {
                res.emplace_back(intervals[i]);
            } else if (intervals[i][0] > newInterval[1]) {
                res.emplace_back(newInterval);
                newInterval = intervals[i];
            } else {
                newInterval[0] = std::min(newInterval[0], intervals[i][0]);
                newInterval[1] = std::max(newInterval[1], intervals[i][1]);
            }
        }
        res.emplace_back(newInterval);
        return res;
    }
};
