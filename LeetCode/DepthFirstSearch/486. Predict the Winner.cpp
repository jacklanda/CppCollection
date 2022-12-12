/* time complexity: O(n) */
/* space complexity: O(n) */

class Solution {
private:
    int getScore(vector<int>& nums, int left, int right) {
        if (left == right)
            return nums[left];
        int select_left = nums[left] - getScore(nums, left + 1, right);
        int select_right = nums[right] - getScore(nums, left, right - 1);
        return std::max(select_left, select_right);
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        return getScore(nums, 0, nums.size() - 1) >= 0;
    }
};
