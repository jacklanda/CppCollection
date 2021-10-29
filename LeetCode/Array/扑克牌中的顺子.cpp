/* 时间复杂度: O(1) */
/* 空间复杂度: O(1) */
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        std::unordered_set<int> s;
        int max_num = INT_MIN, min_num = INT_MAX;
        for (const int& n : nums) {
            if (n == 0) continue;
            if (auto it = s.find(n); it != s.end()) return false;
            s.emplace(n);
            max_num = max(n, max_num);
            min_num = min(n, min_num);
        }
        return max_num - min_num < 5;
    }
};
