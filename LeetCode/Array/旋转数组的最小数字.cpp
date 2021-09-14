/* 双指针法 */
/* 最坏时间复杂度: O(n) */
/* 空间复杂度: O(1) */
class Solution {
public:
    int minArray(vector<int>& numbers) {
        if (numbers.size() == 1) {
            return numbers[0];
        } else if (numbers.size() == 2) {
            return numbers[1] < numbers[0] ? numbers[1] : numbers[0];
        }
        auto rhs = numbers.end() - 1;
        while (rhs != numbers.begin()) {
            auto l_rhs = rhs - 1;
            if (*l_rhs > *rhs) break;
            rhs--;
        }
        return *rhs;
    }
};
