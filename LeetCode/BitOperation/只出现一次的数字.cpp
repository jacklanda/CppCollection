/* 遍历数组进行异或运算 */
/* 时间复杂度: O(n) */
/* 空间复杂度: O(1) */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (auto& n : nums) {
            result ^= n;
        }
        return result;
    }
};
