/* 贪心算法:
 * 每一步取局部最优 => 全局最优*/
/* 时间复杂度: O(n) */
/* 空间复杂度: O(1) */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover{0};
        for (int i = 0; i < nums.size(); ++i) {
            if (i > cover)
                return false;
            else
                cover = std::max(cover, i + nums[i]);
        }
        return true;
    }
};

/* 动态规划 */
/* 时间复杂度: O(n) */
/* 空间复杂度: O(1) */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int dp = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (dp == 0) return false;
            dp = std::max(dp - 1, nums[i]);
        }
        return true;
    }
};
