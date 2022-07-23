class NumArray {
public:
    NumArray(vector<int>& nums) : nums(nums) {
        for(int& num : nums)
            total += num;
    }
    
    void update(int index, int val) {
        total -= nums[index];
        nums[index] = val;
        total += val;
    }
    
    int sumRange(int left, int right) {
        int tmpSum = total;
        
        // the sum we are looking for is a majority of the container, so remove the excess
        if(right - left > nums.size() / 2) {
            for(int x = 0; x < left; ++x)
                tmpSum -= nums[x];
            
            for(int x = right + 1; x < nums.size(); ++x)
                tmpSum -= nums[x];
        } else {
            // sum we are looking for is a minority of the container, so just add it
            tmpSum = 0;
            for(int x = left; x <= right; ++x)
                tmpSum += nums[x];
        }
        
        return tmpSum;
    }
    
private:
    vector<int> nums;
    int total = 0;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
