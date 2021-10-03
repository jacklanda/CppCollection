/* 逻辑与运算 */
/* 时间复杂度: O(n) */
/* 空间复杂度: O(n) */
class Solution {
public:
    int sumNums(int n) {
        n && (n += sumNums(n - 1));
        return n;
    }
};

/* 逻辑或运算 */
class Solution {
public:
    int sumNums(int n) {
        !n || (n += sumNums(n - 1));
        return n;
    }
};
