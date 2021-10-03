/* 暴力法 */
/* 时间复杂度: O((m+n)log(m+n)) */
/* 空间复杂度: O(log(m+n)) */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int& ele : nums2) {
            nums1[m++] = ele;
        }
        std::sort(nums1.begin(), nums1.end());
    }
};

/* 双指针 */
/* 时间复杂度: O(m+n) */
/* 空间复杂度: O(m+n) */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0, k = 0;
        int arr[m + n];

        while (i < m && j < n) {
            if (nums1[i] <= nums2[j])
                arr[k++] = nums1[i++];
            else if (nums1[i] > nums2[j])
                arr[k++] = nums2[j++];
        }
        if (i < m) {
            for (int p = k; p < m + n; ++p) {
                arr[p] = nums1[i++];
            }
        } else if (j < n) {
            for (int p = k; p < m + n; ++p) {
                arr[p] = nums2[j++];
            }
        }

        for (int q = 0; q < m + n; ++q) {
            nums1[q] = arr[q];
        }
    }
};

/* 逆向双指针法 */
/* 时间复杂度: O(m+n) */
/* 空间复杂度: O(1) */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        m--;
        n--;
        int i = nums1.size() - 1;
        while (n >= 0) {
            while (m >= 0 && nums1[m] > nums2[n]) {
                swap(nums1[i--], nums1[m--]);
            }
            swap(nums1[i--], nums2[n--]);
        }
    }
};

