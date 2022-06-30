/* time complexity: O(n*2^n) */
/* space complexity: O(target) */

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::vector<int> current_path;
        std::vector<std::vector<int>> res;
        dfs(candidates, target, res, current_path, 0);
        return res;
    }

private:
    void dfs(std::vector<int>& candidates, int target, std::vector<std::vector<int>>& res, std::vector<int>& current_path, int start) {
        if (target < 0) return;
        if (target == 0) {
            res.emplace_back(current_path);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            current_path.emplace_back(candidates[i]);
            dfs(candidates, target - candidates[i], res, current_path, i);
            current_path.pop_back();
        }
    }
};
