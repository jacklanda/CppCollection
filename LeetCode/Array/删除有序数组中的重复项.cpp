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
        if (!nums.size()) return 0;
        int i = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[i] != nums[j]) nums[++i] = nums[j];
        }
        return i + 1;
    }
};
