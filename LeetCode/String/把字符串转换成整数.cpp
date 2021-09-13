#include <tuple>

/* 法一: 使用long，避免溢出 */
class Solution {
public:
    int strToInt(string str) {
        long num{0};
        int sign{1};
        auto iter{str.begin()};

        while (*iter == ' ') {
            ++iter;
        }
        if (*iter == '-') sign = -1;
        if (*iter == '+' || *iter == '-') ++iter;
        if (!isdigit(*iter)) return 0;

        while (isdigit(*iter) && iter != str.end()) {
            num = num * 10 + (*iter - '0');
            if (num > INT_MAX && sign == 1)
                return INT_MAX;
            else if (num > INT_MAX && sign == -1)
                return INT_MIN;
            ++iter;
        }

        return num * sign;
    }
};

/* 法二: 无long，循环体内进行溢出检查 */
class Solution {
public:
    int strToInt(string str) {
        int num{0}, sign{1};
        auto iter{str.begin()};

        while (*iter == ' ') {
            ++iter;
        }
        if (*iter == '-') sign = -1;
        if (*iter == '+' || *iter == '-') ++iter;
        if (!isdigit(*iter)) return 0;

        while (isdigit(*iter) && iter != str.end()) {
            if (num > INT_MAX / 10 || (num == INT_MAX / 10 && *iter - '0' > 7))
                return sign == 1 ? INT_MAX : INT_MIN;
            num = num * 10 + (*iter - '0');
            ++iter;
        }
        return num * sign;
    }
};
