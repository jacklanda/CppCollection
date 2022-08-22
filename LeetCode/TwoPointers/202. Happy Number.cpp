/* time complexity: O(n) */
/* space complexity: O(1) */

class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        do {
            slow = bit_square_sum(slow);
            fast = bit_square_sum(fast);
            fast = bit_square_sum(fast);
        } while (slow != fast);
        
        return fast == 1;
    }
    
private:
    int bit_square_sum(int n) {
        int sum = 0;
        while (n > 0) {
            int bit = n % 10;
            sum += bit * bit;
            n = n / 10;
        }
        return sum;
    }
};
