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
