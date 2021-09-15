/* 时间复杂度: O(k), 常数k取决于整数的二进制位数 */
/* 空间复杂度: O(1) */
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sum{0};
        uint32_t flag{1};
        while (flag) {
            if (n & flag) ++sum;
            flag = flag << 1;
        }
        return sum;
    }
};

/* 时间复杂度: O(k), 常数k取决于待判断的二进制数中1的位数 */
/* 空间复杂度: O(1) */
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sum{0};
        while (n) {
            ++sum;
            n = n & (n - 1);
        }
        return sum;
    }
};
