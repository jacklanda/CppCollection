/* time complexity: O(log(n)) */
/* space complexity: O(1) */

class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) return false;

        std::vector<int> primes{2, 3, 5};
        for (const int& prime : primes)
            while (n % prime == 0) n /= prime;

        return n == 1;
    }
};
