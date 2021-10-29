/* 时间复杂度: O(n) */
/* 空间复杂度: O(1); */
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            while (low < high && ((nums[low] & 0x1) == 1)) ++low;
            while (low < high && ((nums[high] & 0x1) == 0)) --high;
            swap(nums[low++], nums[high--]);
        }
        return nums;
    }
};
