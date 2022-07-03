/* time complexity: O(n) */
/* space complexity: O(1) */

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        for (const int& num : arr)
            if (num <= k) ++k;
        return k;
    }
};
