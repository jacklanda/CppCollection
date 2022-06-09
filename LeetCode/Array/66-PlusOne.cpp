/* time complexity: O(n) */
/* space complexity: O(n) */

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        std::deque<int> dq;
        bool is_carry = false;
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (is_carry || i == digits.size() - 1) {
                ++digits[i];
                is_carry = false;
            }
            if (digits[i] == 10) {
                is_carry = true;
                dq.emplace_front(0);
            } else {
                dq.emplace_front(digits[i]);
            }
        }
        if (is_carry) dq.emplace_front(1);
        return std::vector<int>(dq.begin(), dq.end());
    }
};

/* time complexity: O(n) */
/* space complexity: O(1) */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
            *it += carry;
            carry = *it / 10;
            *it %= 10;
        }
        if (carry > 0) digits.insert(digits.begin(), 1);
        return digits;
    }
};
