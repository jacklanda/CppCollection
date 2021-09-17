/* 时间复杂度: O(nlogn+n) */
/* 空间复杂度: O(n) */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::map<int, int> m;
        for (auto n : nums) {
            if (m.find(n) != m.end())
                ++m[n];
            else
                m[n] = 1;
        }
        std::vector<std::pair<int, int>> vec(m.begin(), m.end());
        sort(vec.begin(), vec.end(), [](auto x, auto y) {
            if (x.second == y.second)
                return x.first < y.first;
            else
                return x.second > y.second;
        });
        return (*vec.begin()).first;
    }
};
