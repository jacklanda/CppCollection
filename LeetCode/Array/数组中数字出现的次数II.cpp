class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> hash_map;
        for(int n : nums) hash_map[n]++;
        for(auto iter = hash_map.begin(); iter != hash_map.end(); iter++){
            if(iter->second == 1) return iter->first;
        }
        return -1;
    }
};
