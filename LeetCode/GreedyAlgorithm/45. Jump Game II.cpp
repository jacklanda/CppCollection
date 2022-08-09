/* time complexity: O(n) */
/* space complexity: O(1) */

class Solution {
public:
    int jump(vector<int>& nums) {
        int curr_cover = 0, next_cover = 0, res = 0;
        
        for (int i = 0; i < nums.size() - 1; ++i) {
            next_cover = std::max(i + nums[i], next_cover);
            if (i == curr_cover) {
                ++res;
                curr_cover = next_cover;
            }
        }
        
        return res;
    }
};
