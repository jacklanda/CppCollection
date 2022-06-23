/* using division */
/* time complexity: O(n) */
/* space complexity: O(1) */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1, zero_count = std::count(nums.begin(), nums.end(), 0);
        if (zero_count > 1) return std::vector<int>(nums.size(), 0);
        for (const int& num : nums)
            if (num) product *= num;
        for (int& num : nums) {
            if (zero_count)
                num = num == 0 ? product : 0;
            else
                num = product / num;
        }
        return nums;
    }
};

/* using prefix & suffix simultaneously */
/* time complexity: O(n) */
/* space complexity: O(1) */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefix = 1, suffix = 1;
        std::vector<int> products(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            products[i] = prefix;
            prefix *= nums[i];
        }
        for (int i = nums.size() - 1; i >= 0; --i) {
            products[i] *= suffix;
            suffix *= nums[i];
        }
        return products;
    }
};
