/* At most K duplicates(here is 2) */
/* time complexity: O(n) */
/* space complexity: O(1) */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int& num : nums) {
            if (i < 2 || num > nums[i - 2]) nums[i++] = num;
        }
        return i;
    }
};
