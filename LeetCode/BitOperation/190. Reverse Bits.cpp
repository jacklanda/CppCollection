/* time complexity: O(n) */
/* space complexity: O(n) */

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> bs{n};
        int low = 0, high = 31;
        while (low < high) {
            bool tmp = bs[low];
            bs[low++] = bs[high];
            bs[high--] = tmp;
        }
        return bs.to_ulong();
    }
};
