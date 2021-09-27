/* 时间复杂度: O(n) */
/* 空间复杂度: O(k)  */
class Solution {
public:
    char firstUniqChar(string s) {
        // auto len = [&s]()->constexpr{return s.size();}();
        // std::array<int, s.size()> arr;
        std::unordered_map<char, int> m;
        for (auto c : s) ++m[c];
        for (auto c : s) {
            if (m[c] == 1) return c;
        }
        return ' ';
    }
};

/* 用 C-like Array 替代哈希表 */
/* 时间复杂度: O(n) */
/* 空间复杂度: O(k), k=26  */
class Solution {
public:
    char firstUniqChar(string s) {
        int arr['z' + 1] = {0};
        for (auto c : s) ++arr[c];
        for (auto c : s) {
            if (arr[c] == 1) return c;
        }
        return ' ';
    }
};
