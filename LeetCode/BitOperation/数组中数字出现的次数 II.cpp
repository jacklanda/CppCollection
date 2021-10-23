/* 时间复杂度: O(n) */
/* 空间复杂度: O(1) */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0, sub = 0; i < 32; ++i, sub = 0) {
            for (const int& n : nums) sub += ((n >> i) & 1);
            if (sub % 3) res |= (1 << i);
        }
        return res;
    }
};
