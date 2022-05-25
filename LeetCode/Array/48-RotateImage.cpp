/* bad approach: use a assistant matrix */
/* time complexity: O(n^2) */
/* space complexity: O(n^2) */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        std::vector<vector<int>> assist_matrix = matrix;
        for (int i = matrix.size() - 1, k = 0; i >= 0; --i, ++k) {  // i -> row
            for (int j = 0; j < matrix[0].size(); ++j) {
                assist_matrix[j][k] = matrix[i][j];
            }
        }
        matrix = assist_matrix;
    }
};

/* two times flipping equal to rotation */
/* time complexity: O(n^2) */
/* space complexity: O(1) => rotate in-place */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        // flip on the horizontal axix
        for (int i = 0; i < (row >> 1); ++i) {
            for (int j = 0; j < col; ++j) {
                std::swap(matrix[i][j], matrix[row - i - 1][j]);
            }
        }
        // flip on the main diagonal
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
