/* 时间复杂度: O(n^2) => 超时！ */
/* 空间复杂度: O(1) */
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int sum = 0;
            for (int j = i; j >= 0; --j) {
                sum += nums[j];
                if (sum == k) ++count;
            }
        }
        return count;
    }
};

/* 前缀和 + 辅助哈希表 */
/* 时间复杂度: O(n) */
/* 空间复杂度: O(n) */
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = 1;
        int count = 0, prev = 0;
        for (const int n : nums) {
            prev += n;
            if (m.find(prev - k) != m.end()) {
                count += m[prev - k];
            }
            m[prev]++;
        }
        return count;
    }
};
