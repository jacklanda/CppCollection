/* 简单的贪心 */
/* 时间复杂度: O(n) */
/* 空间复杂度: O(n) */
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        std::unordered_set<int> hash_set(candyType.begin(), candyType.end());
        return std::min(hash_set.size(), candyType.size() / 2);
    }
};
