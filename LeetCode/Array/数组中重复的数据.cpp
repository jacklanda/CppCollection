/* 使用一个辅助哈希表 */
/* 时间复杂度: O(n) */
/* 空间复杂度: O(n) */
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        std::unordered_set<int> s;
        std::vector<int> res;
        res.reserve(nums.size());
        for (auto& n : nums) {
            if (s.count(n)) res.emplace_back(n);
            s.emplace(n);
        }
        return res;
    }
};
