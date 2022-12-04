/* time complexity: O(k), k depends on the bits number of the uint. */
/* space complexity: O(1) */
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

/* time complexity: O(k), k depends on the bits number of the uint. */
/* space complexity: O(1) */
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
