/* 数组排序法 */
/* 时间复杂度: O(nlogn) */
/* 空间复杂度: O(1) */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int pos = nums.size() >> 1;
        return nums[pos];
    }
};

/* 哈希表统计法 */
/* 时间复杂度: O(nlogn) */
/* 空间复杂度: O(n) */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::map<int, int> m;
        for (auto n : nums) {
            if (m.find(n) != m.end())
                ++m[n];
            else
                m[n] = 1;
        }
        auto max_pair = std::max_element(
            m.begin(), m.end(),
            [](auto p1, auto p2) { return p1.second < p2.second; });
        return (*max_pair).first;
    }
};

/* 摩尔投票法 */
/* 时间复杂度: O(n) */
/* 空间复杂度: O(1) */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int x, votes = 0;
        for (int n : nums) {
            if (votes == 0) x = n;
            votes += n == x ? 1 : -1;
        }
        return x;
    }
};
