/* 暴力解法 */
/* 时间复杂度: O(n^2) */
/* 空间复杂度: O(n) */
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> vec;
        vec.reserve(std::max(nums1.size(), nums2.size()));
        for (auto& n1 : nums1) {
            for (auto& n2 : nums2) {
                if (n1 == n2) {
                    vec.emplace_back(n1);
                    n2 = INT_MAX;
                    break;
                }
            }
        }
        return vec;
    }
};
