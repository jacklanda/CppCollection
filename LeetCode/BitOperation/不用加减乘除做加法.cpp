/* 迭代位运算 */
/* 时间复杂度: O(n) */
/* 空间复杂度: O(1) */
class Solution {
public:
    int add(int a, int b) {
        while (b != 0) {
            int tmp = (unsigned int)(a & b) << 1;
            a ^= b;
            b = tmp;
        }
        return a;
    }
};

/* 递归位运算 */
/* 时间复杂度: O(n) */
/* 空间复杂度: O(n) */
class Solution {
public:
    int add(int a, int b) {
        return b == 0 ? a : add(a ^ b, (unsigned int)(a & b) << 1);
    }
};
