/* time complexity: O(m*n) */
/* space complexity: O(m+n) */

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        std::vector<bool> row_status(matrix.size(), false);
        std::vector<bool> col_status(matrix[0].size(), false);
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    row_status[i] = true;
                    col_status[j] = true;
                }
            }
        }

        for (int i = 0; i < matrix.size(); ++i) {
            if (!row_status[i]) continue;
            for (int j = 0; j < matrix[0].size(); ++j) matrix[i][j] = 0;
        }
        for (int j = 0; j < matrix[0].size(); ++j) {
            if (!col_status[j]) continue;
            for (int i = 0; i < matrix.size(); ++i) matrix[i][j] = 0;
        }

        return;
    }
};
