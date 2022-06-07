/* bad approach: iterate matrix completely from left-right and top-down directions */
/* time complexity: O(m*n) */
/* space complexity: O(1) */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == target) return true;
            }
        }
        return false;
    }
};

/* efficient approach: leverage sorted array to improve efficiency */
/* time complexity: O(m+n) */
/* space complexity: O(1) */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        for (int i = 0; i < rows; ++i) {
            for (int j = cols - 1; j >= 0; --j) {
                if (matrix[i][j] > target) {
                    continue;
                } else if (matrix[i][j] < target) {
                    break;
                } else if (matrix[i][j] == target) {
                    return true;
                }
            }
        }
        return false;
    }
};

/* Most efficient approach: using binary search to iterate the only potential rows array */
/* time efficiency: O(m+logn) */
/* space efficiency: O(1) */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        for (int i = 0; i < rows; ++i) {
            if (matrix[i][cols - 1] > target)
                return BinarySearch(matrix[i], target, 0, cols - 1);
            else if (matrix[i][cols - 1] == target)
                return true;
            else
                continue;
        }
        return false;
    }

    bool BinarySearch(vector<int>& array, int target, int left, int right) {
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (array[mid] == target)
                return true;
            else if (array[mid] < target)
                left = mid + 1;
            else if (array[mid] > target)
                right = mid - 1;
        }
        return false;
    }
};
