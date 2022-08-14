/* time complexity: O(n) */
/* space complexity: O(1) */

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0, twenty = 0;
        for (int bill : bills) {
            if (bill == 5) {
                ++five;
            } else if (bill == 10 and five > 0) {
                --five;
                ++ten;
            } else if (bill == 20 and five > 0 and ten > 0) {
                --five;
                --ten;
                ++twenty;
            } else if (bill == 20 and five >= 3) {
                five -= 3;
                ++twenty;
            } else {
                return false;
            }
        }
        
        return true;
    }
};
