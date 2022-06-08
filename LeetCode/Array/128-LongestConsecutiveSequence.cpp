/* using a hashtable to record every element used or not
 * centered on this element, expand to left and right, until non-consective,
 * and then record the longest sequence length. */
/* time complexity: O(n) */
/* space complexity: O(n) */

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 0;
        std::unordered_map<int, bool> used;
        for (const int& num : nums) used[num] = false;

        for (int& num : nums) {
            if (used[num]) continue;

            int length = 1;

            used[num] = true;
            for (int i = num + 1; used.find(i) != used.end(); ++i) {
                used[i] = true;
                ++length;
            }
            for (int i = num - 1; used.find(i) != used.end(); --i) {
                used[i] = true;
                ++length;
            }

            longest = std::max(longest, length);
        }

        return longest;
    }
};
