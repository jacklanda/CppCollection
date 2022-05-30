/* 投机取巧法:
 * 时间复杂度：O(n)
 * 空间复杂度：O(1) */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto it = std::unique(nums.begin(), nums.end());
        return std::distance(nums.begin(), it);
    }
};

/* 双指针法：
 * 时间复杂度：O(n)
 * 空间复杂度：O(1) */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int idx = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != nums[idx]) nums[++idx] = nums[i];
        }
        return idx + 1;
    }
};
