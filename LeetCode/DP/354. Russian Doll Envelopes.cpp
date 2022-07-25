/* time complexity: O(n*log(n)) */
/* space complexity: O(n) */

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        std::vector<int> dp;
        std::sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b){
            return a.front() < b.front() or (a.front() == b.front() and a.back() > b.back());
        });
        for (auto& envelope : envelopes) {
            auto iter = std::lower_bound(dp.begin(), dp.end(), envelope.back());
            if (iter == dp.end())
                dp.emplace_back(envelope.back());
            else if (envelope.back() < *iter)
                *iter = envelope.back();
        }
        return dp.size();
    }
};
