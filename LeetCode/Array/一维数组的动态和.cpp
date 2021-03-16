class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int temp = 0;
        for (auto i = nums.begin(); i < nums.end(); i++) {
            temp += *i;
            *i = temp;
        }
        return nums;
    }
};
