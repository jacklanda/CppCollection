/* time complexity: O(n) */
/* space complexity: O(1) */

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int flag = 1;
        for (const int& num : nums) {
            if (num == 0)
                return 0;
            else if (num > 0)
                flag *= 1;
            else if (num < 0)
                flag *= -1;
        }
        return flag;
    }
};
