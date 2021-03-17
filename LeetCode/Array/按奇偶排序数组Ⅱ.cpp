/* 原地修改法 */
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        for (int i = 1, j = 0; j < nums.size(); j += 2) {
            if (nums[j] % 2 == 1) {
                while (nums[i] % 2 == 1) {
                    i += 2;
                }
                swap(nums[i], nums[j]);
            }
        }
        return nums;
    }
};
