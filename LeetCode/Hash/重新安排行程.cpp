/* 时间复杂度: O(n) */
/* 空间复杂度: O(n) */
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        std::vector<std::string> result;
        if (tickets.empty()) return result;
        std::unordered_map<std::string, std::multiset<std::string>> m;
        for (auto& ticket : tickets) {
            m[ticket[0]].emplace(ticket[1]);
        }
        std::stack<string> stk;
        stk.emplace("JFK");
        while (!stk.empty()) {
            std::string next = stk.top();
            if (!m[next].empty()) {
                stk.emplace(*m[next].begin());
                m[next].erase(m[next].begin());
            } else if (m[next].empty()) {
                result.emplace_back(next);
                stk.pop();
            }
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};
