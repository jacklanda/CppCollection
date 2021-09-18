/* trick: 调用c++库函数std::next_permutation()获取字符串的全排列 */
/* 时间复杂度 : O(n) */
/* 空间复杂度: O(n) */
class Solution {
public:
    vector<string> permutation(string s) {
        if (s.empty() || s.size() == 1) return {s};
        std::vector<std::string> vec;
        std::sort(s.begin(), s.end());
        do {
            vec.emplace_back(s);
        } while (std::next_permutation(s.begin(), s.end()));
        return vec;
    }
};

