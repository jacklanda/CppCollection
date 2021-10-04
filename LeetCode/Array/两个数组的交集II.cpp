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

/* 以空间换时间
 * 使用一个辅助的哈希重复集合
 **/
/* 时间复杂度: O(n) */
/* 空间复杂度: O(n) */
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_multiset<int> s(nums1.begin(), nums1.end());
        std::vector<int> vec;
        vec.reserve(std::max(nums1.size(), nums2.size()));
        for (auto& n : nums2) {
            auto it = s.find(n);
            if (it != s.end() && *it != INT_MAX) {
                vec.emplace_back(n);
                s.erase(it);
            }
        }
        return vec;
    }
};
