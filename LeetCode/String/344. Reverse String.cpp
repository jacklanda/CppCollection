/* time complexity: O(n) */
/* space complexity: O(1) */

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            std::swap(s[left++], s[right--]);   
        }
    }
};
