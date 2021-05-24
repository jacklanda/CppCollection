class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int, bool> hash_map;
        for(int n : nums){
            if(hash_map[n]) return n;
            hash_map[n] = true;
        }
        return -1;
    }
};
