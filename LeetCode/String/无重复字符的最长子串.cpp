/* 滑动窗口
 * 利用哈希集合
 * 进行一次遍历 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        unordered_set<char> set;
        int max_len = 0, left = 0;
        for (int i = 0; i < s.size(); i++) {
            while (set.find(s[i]) != set.end()) {
                set.erase(s[left]);
                left++;
            }
            set.insert(s[i]);
            max_len = max(max_len, i - left + 1);
        }
        return max_len;
    }
};
