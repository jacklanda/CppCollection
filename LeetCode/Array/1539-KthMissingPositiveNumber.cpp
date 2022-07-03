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

/* time complexity: O(log(n)) */
/* space complexity: O(1) */

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0, right = arr.size();
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (arr[mid] - mid - 1 < k)
                left = mid + 1;
            else
                right = mid;
        }
        return left + k;
    }
};
