/* time complexity: O(n) */
/* space complexity: O(n) */

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int count[2001] = {0};
        for (int i = 0; i < arr.size(); ++i)
            ++count[arr[i] + 1000];
        
        bool freq[1001] = {false};
        for (int i = 0; i <= 2000; ++i) {
            if (count[i]) {
                if (freq[count[i]] == false) freq[count[i]] = true;
                else return false;
            }
        }
        return true;
    }
};
