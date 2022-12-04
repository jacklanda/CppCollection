/* Bucket Sort Approach */
/* time complexity: O(n) */
/* space complexity: O(n) */

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int max_freq = 0;
        unordered_map<int, int> num2freq;
        for (const int& num : nums) {
            max_freq = std::max(max_freq, ++num2freq[num]);
        }
        
        vector<vector<int>> buckets(3);
        for (const auto& pair : num2freq) {
            for (int i = 0; i < pair.second; ++i) {
                buckets[pair.first].emplace_back(pair.first);
            }
        }
        
        nums.clear();
        for(const vector<int>& bucket : buckets) {
            for (const int& num : bucket)
                nums.emplace_back(num);
        }
    }
};

/* Two-pointers Approach */
/* time complexity: O(n) */
/* space complexity: O(n) */
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, midd = 0, right = nums.size() - 1;
        while (midd <= right) {
            if (nums[midd] == 0)
                std::swap(nums[midd++], nums[left++]);
            else if (nums[midd] == 1)
                midd++;
            else
                std::swap(nums[midd], nums[right--]);
        }
    }
};
