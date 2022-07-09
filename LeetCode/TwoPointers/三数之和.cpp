/* 双指针法是该问题的最优解法 */
/* 时间复杂度：O(n^2) */
/* 空间复杂度: O(1) */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        std::sort(nums.begin(), nums.end());  // 先对数组进行排序
        for (int i = 0; i < nums.size(); ++i) {
            int j = i + 1, k = nums.size() - 1;
            if (i >= 1 && nums[i] == nums[i - 1]) continue;  // 对i去重
            while (j < k) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {  // 对j去重
                    ++j;
                    continue;
                }
                if (k < nums.size() - 1 && nums[k] == nums[k + 1]) {  // 对k去重
                    --k;
                    continue;
                }
                if (nums[i] + nums[j] + nums[k] > 0)
                    --k;
                else if (nums[i] + nums[j] + nums[k] < 0)
                    ++j;
                else if (nums[i] + nums[j] + nums[k] == 0) {
                    res.emplace_back(vector<int>{nums[i], nums[j], nums[k]});
                    ++j;
                }
            }
        }
        return res;
    }
};
