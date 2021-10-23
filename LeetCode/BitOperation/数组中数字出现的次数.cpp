/* 本题为数组中只出现一次的数字的升级版 */
/* 找到数组的分界点，进行分组异或即可 */
/* 时间复杂度: O(n) */
/* 空间复杂度: O(1) */
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int x = 0, y = 0, n = 0, m = 1;
        for (const int& num : nums) n ^= num;
        while ((n & m) == 0) m <<= 1;
        for (const int& num : nums) {
            if (num & m)
                x ^= num;
            else
                y ^= num;
        }
        return {x, y};
    }
};
