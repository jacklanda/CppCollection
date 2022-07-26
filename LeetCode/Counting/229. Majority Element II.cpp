/* time complexity: O(n) */
/* space complexity: O(1) */

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        std::vector<int> res;
        const int size = nums.size();
        int num1 = -1, num2 = -1, count1 = 0, count2 = 0;
        for (int i = 0; i < size; ++i) {
            if (nums[i] == num1) {
                ++count1;
            } else if (nums[i] == num2) {
                ++count2;
            } else if (count1 == 0) {
                num1 = nums[i];
                count1 = 1;
            } else if (count2 == 0) {
                num2 = nums[i];
                count2 = 1;
            } else {
                --count1;
                --count2;
            }
        }
        
        int freq1 = std::count(nums.begin(), nums.end(), num1);
        int freq2 = std::count(nums.begin(), nums.end(), num2);
        if (freq1 > size / 3) res.emplace_back(num1);
        if (num1 != num2 and freq2 > size / 3) res.emplace_back(num2);  // avoid duplication
        
        return res;
    }
};
