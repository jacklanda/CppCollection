/* Brutal Force 1: Sort + Math */
/* time complexity: O((m+n)log(m+n)) */
/* space complexity: O(log(m+n)) */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for (const int& num : nums2) nums1.emplace_back(num);
        std::sort(nums1.begin(), nums1.end());
        return nums1.size() & 0x01 ? nums1[nums1.size() / 2.0] : (nums1[nums1.size() / 2 - 1] + nums1[nums1.size() / 2]) / 2.0;
    }
};

/* Brutal Force 2: Merge + Math */
/* time complexity: O(m+n) */
/* space complexity: O(m+n) */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0, k = 0;
        std::vector<int> nums3(nums1.size() + nums2.size(), 0);
        while (i < nums1.size() && j < nums2.size()) nums3[k++] = nums1[i] < nums2[j] ? nums1[i++] : nums2[j++];
        while (i < nums1.size()) nums3[k++] = nums1[i++];
        while (j < nums2.size()) nums3[k++] = nums2[j++];
        return nums3.size() & 0x01 ? nums3[nums3.size() / 2] : (nums3[nums3.size() / 2 - 1] + nums3[nums3.size() / 2]) / 2.0;
    }
};

/* Two Pointer */
/* time complexity: O(m+n) */
/* space complexity: O(1) */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), i = 0, j = 0, l = 0, r = 0;
        for (int k = 0; k < (m + n) / 2 + 1; ++k) {
            l = r;
            r = (i < m && (j >= n || nums1[i] < nums2[j])) ? nums1[i++] : nums2[j++];
        }
        return (m + n) & 0x01 ? r : (l + r) / 2.0;
    }
};
