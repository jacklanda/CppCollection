/* 使用unordered_map 辅助记录重复值 */
/* 时间复杂度: O(n) */
/* 空间复杂度: O(n) */
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int, bool> hash_map;
        for (int n : nums) {
            if (hash_map[n]) return n;
            hash_map[n] = true;
        }
        return -1;
    }
};

/* 使用 unordered_set 辅助记录重复值 */
/* 时间复杂度: O(n) */
/* 空间复杂度: O(n) */
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        std::unordered_set<int> s;
        for (const int& n : nums) {
            auto it = s.find(n);
            if (it == s.end()) {
                s.insert(n);
            } else if (it != s.end()) {
                return *it;
            }
        }
        return 0;
    }
};

/* 使用C-like array 辅助记录重复值 */
/* 时间复杂度: O(n) */
/* 空间复杂度: O(n) */
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int arr[nums.size()];
        memset(arr, 0, sizeof(arr));
        for (const int& n : nums) {
            if (arr[n] == 0) {
                ++arr[n];
            } else if (arr[n] != 0) {
                return n;
            }
        }
        return 0;
    }
};
