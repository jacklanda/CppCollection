/* time complexity: O(nlog(n)) */
/* space complexity: O(log(n)) */

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return intervals;
        std::sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        res.emplace_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (res.back()[1] >= intervals[i][0])
                res.back()[1] = std::max(res.back()[1], intervals[i][1]);
            else
                res.emplace_back(intervals[i]);
        }
        return res;
    }
};
