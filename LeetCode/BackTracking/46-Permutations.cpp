class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) return {};
        vector<vector<int>> res;
        backtrack(nums, 0, res);
        return res;
    }

    void backtrack(vector<int>& nums, int level, vector<vector<int>>& res) {
        if (level == nums.size() - 1) {
            res.emplace_back(nums);
            return;
        }
        for (int i = level; i < nums.size(); ++i) {
            std::swap(nums[i], nums[level]);
            backtrack(nums, level + 1, res);
            std::swap(nums[i], nums[level]);
        }
    }
};
