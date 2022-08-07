/* time complexity: O(n*log(n)) */
/* space complexity: O(n) */

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        std::vector<int> vec = nums;
        std::sort(vec.begin(), vec.end());
        int hash_map[101];
        
        for (int i = nums.size() - 1; i >= 0; --i)
            hash_map[vec[i]] = i;
        
        for (int i = 0; i < nums.size(); ++i)
            vec[i] = hash_map[nums[i]];
        
        return vec;
    }
};
