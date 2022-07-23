/* Brute Force */

class NumArray {
public:
    NumArray(vector<int>& nums) : nums(nums) {}
    
    int sumRange(int left, int right) {
        int sum = 0;
        for (int i = left; i <= right; ++i)
            sum += nums[i];
        return sum;
    }
    
private:
    std::vector<int>& nums;
};

class NumArray {
public:
    NumArray(vector<int>& nums) : nums(nums) {
        for (int i = 1; i < nums.size(); ++i)
            nums[i] += nums[i - 1];
    }

    int sumRange(int left, int right) {
        return left == 0 ? nums[right] : nums[right] - nums[left - 1];
    }

private:
    std::vector<int>& nums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
