/* time complexity: O(n) */
/* space complexity: O(n) */

class Solution {
public:
    int nextGreaterElement(int n) {
        auto digits = std::to_string(n);
        std::next_permutation(begin(digits), end(digits));
        auto res = std::stoll(digits);
        return (res > INT_MAX || res <= n) ? -1 : res;
    }
};
