/* 时间复杂度: O(十进制数字x的位数) */
/* 空间复杂度: O(1) */
class Solution {
public:
    int reverse(int x) {
        int num{0}, digit{0};
        while (x != 0) {
            if (num < INT_MIN / 10 || num > INT_MAX / 10) return 0;
            digit = x % 10;
            x /= 10;
            num = num * 10 + digit;
        }
        return num;
    }
};
