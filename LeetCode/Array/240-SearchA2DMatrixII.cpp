/* Time Limit Exceeded! */
/* time complexity: O(m*n) */
/* space complexity: O(1) */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == target)
                    return true;
                else if (matrix[i][j] < target)
                    continue;
                else if (matrix[i][j] > target)
                    break;
            }
        }
        return false;
    }
};

/* Simple BinarySearch Approach */
/* time complexity: O(m*logn) */
/* space complexity: O(1) */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        for (int i = 0; i < rows; ++i) {
            if (target >= matrix[i][0] && target <= matrix[i][cols - 1] && BinarySearch(matrix[i], target, 0, cols - 1)) return true;
        }
        return false;
    }

    bool BinarySearch(vector<int>& array, int target, int low, int high) {
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (array[mid] == target)
                return true;
            else if (array[mid] > target)
                high = mid - 1;
            else if (array[mid] < target)
                low = mid + 1;
        }
        return false;
    }
};
