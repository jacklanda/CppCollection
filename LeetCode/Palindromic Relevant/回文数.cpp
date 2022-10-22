class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || x != 0 && x % 10 == 0) return false;
        int temp = x;
        int result = 0;
        while (temp) {
            if (result > INT_MAX / 10) return false;
            result = result * 10 + temp % 10;
            temp /= 10;
        }
        return result == x ? true : false;
    }
};
