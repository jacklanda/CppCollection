/* Classic Merge Sort on Array */
/* Time complexity: O(n*log(n)) */
/* Space complexity: O(n) */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // classic merge sort algo on array
        // std::vector<int> temp(m+n, 0);
        int temp[m + n];  // temp array
        int i = 0, j = 0, k = 0;
        while (i < m && j < n) temp[k++] = nums1[i] < nums2[j] ? nums1[i++] : nums2[j++];
        while (i < m) temp[k++] = nums1[i++];
        while (j < n) temp[k++] = nums2[j++];
        for (k = 0; k < m + n; ++k) nums1[k] = temp[k];    
    }
};
