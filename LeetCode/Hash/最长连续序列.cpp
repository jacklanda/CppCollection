/* 时间复杂度: O(n) */
/* 空间复杂度: O(n) */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> s(nums.begin(), nums.end());
        int result = 0;
        while (!s.empty()) {
            int cur = *(s.begin());
            s.erase(cur);
            int prev = cur - 1, next = cur + 1;
            while (s.count(next)) {
                s.erase(next++);
            }
            while (s.count(prev)) {
                s.erase(prev--);
            }
            result = std::max(result, next - prev - 1);
        }
        return result;
    }
};
