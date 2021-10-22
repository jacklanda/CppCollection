/* 哈希表+一次遍历 */
/* 时间复杂度: O(n) */
/* 空间复杂度: O(n) */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_set<int> s(nums.begin(), nums.end());
        for (int n : nums) {
            auto it = s.find(target - n);
            if (it != s.end()) return {*it, n};
        }
        return {};
    }
};

/* (迭代式)二分查找 */
/* 时间复杂度: O(nlogn) */
/* 空间复杂度: O(1) */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            int n = target - nums[i], low = i, high = nums.size() - 1;
            while (low <= high) {
                int mid = low + ((high - low) >> 1);
                if (nums[mid] > n)
                    high = mid - 1;
                else if (nums[mid] < n)
                    low = mid + 1;
                else if (nums[mid] == n)
                    return {nums[mid], nums[i]};
            }
        }
        return {};
    }
};

/* 双指针法 */
/* 时间复杂度: O(n) */
/* 空间复杂度: O(1) */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int low = 0, high = (int)nums.size() - 1;
        while (low < high) {
            if (nums[low] == target - nums[high])
                return {nums[low], nums[high]};
            else if (nums[low] < target - nums[high])
                ++low;
            else if (nums[low] > target - nums[high])
                --high;
        }
        return {};
    }
};

