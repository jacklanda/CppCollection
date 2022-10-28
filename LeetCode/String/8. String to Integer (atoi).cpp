/* time complexity: O(n) */
/* space complexity: O(1) */

class Solution {
public:
    int myAtoi(string s) {
        long result = 0;
        int indicator = 1;
        int i = s.find_first_not_of(' ');

        if (i >= 0) {  // i can be -1, if the string is empty
            if (s[i] == '-' || s[i] == '+')
                indicator = (s[i++] == '-') ? -1 : 1;

            while (i < s.size() && isdigit(s[i])) {
                result = result * 10 + (s[i++] - '0');
                //corner cases
                if (result * indicator >= INT_MAX) return INT_MAX;
                if (result * indicator <= INT_MIN) return INT_MIN;
            }
        }
        
        return result * indicator;
    }
};
