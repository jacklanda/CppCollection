/* time complexity: O(n) */
/* space complexity: O(1) */

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        
        int curr = 0, next = 1;
        int cnt = 1, max_cnt = 1;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[curr] < nums[next])
                cnt++;
            else
                cnt = 1;
            max_cnt = std::max(cnt, max_cnt);
            curr++;
            next++;
        }
        return max_cnt;
    }
};
