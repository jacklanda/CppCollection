/* Using STL function
 * time complexity: O(n)
 * space complexity: O(1) */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto it = std::unique(nums.begin(), nums.end());
        return std::distance(nums.begin(), it);
    }
};

/* Two pointer approach
 * time complexity: O(n)
 * space complexity: O(1) */
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
