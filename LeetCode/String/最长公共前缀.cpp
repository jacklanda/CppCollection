/* 时间复杂度: O(nlogn) */
/* 空间复杂度: O(logn) => sort快排的递归栈深度 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::sort(strs.begin(), strs.end());

        int end_pos{0};
        string front_str = strs.front();
        string back_str = strs.back();
        for (int l = 0; l < strs[0].size(); ++l) {
            if (front_str[l] == back_str[l])
                ++end_pos;
            else
                break;
        }

        return string(front_str, 0, end_pos);
    }
};
