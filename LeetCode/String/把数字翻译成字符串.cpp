/* 思路分析:
12258  ->  1  2  2  5  8
           b  c  c  f  i

       ->  1  22 5  8
           b  w  f  i

       ->  1  2  25 8
           b  c  z  i

       ->  12 2  5  8
           m  c  f  i

- 操作说明：
  - `num % 100` 表示取 num 的最后两位数；
  - `num / 10` 表示取 num 的左边两位数；
  - `num / 100` 表示取 num 的左边一位数；
- 本题可划分为3种情况：
  1. 0 <= num <= 9 时，num 的个位和十位数字无法结合，递归终止，返回 1；
  2. 10 <= num % 100 <= 25 时，可衍生出2种表示方法，故用
     `translateNum(num / 100) + translateNum(num / 10)` 来递归计算表示方法；
  3. num % 100 < 10 || num % 100 > 25 时，个位十位不可拆，故使用
     `translateNum(num / 10)` 计算。
*/

/* 纯递归 */
/* 时间复杂度: O(n) */
/* 空间复杂度: O(n) */
class Solution {
public:
    int translateNum(int num) {
        if (num < 10) return 1;
        if (num % 100 >= 10 && num % 100 <= 25) {
            return translateNum(num / 100) + translateNum(num / 10);
        } else {
            return translateNum(num / 10);
        }
    }
};
