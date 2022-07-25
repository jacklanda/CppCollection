class Solution {
public:
    string longestDiverseString(int a, int b, int c, char A = 'a', char B = 'b', char C = 'c') {
        if (a < b)
            return longestDiverseString(b, a, c, B, A, C);
        if (b < c)
            return longestDiverseString(a, c, b, A, C, B);
        if (b == 0)
            return std::string(std::min(2, a), A);
        
        auto use_a = std::min(2, a), use_b = a - use_a >= b ? 1 : 0;
        return std::string(use_a, A) + std::string(use_b, B) + longestDiverseString(a - use_a, b - use_b, c, A, B, C);
    }
};
