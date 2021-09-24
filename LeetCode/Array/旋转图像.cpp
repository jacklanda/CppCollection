/* 暴力法：使用一个辅助矩阵 */
/* 时间复杂度: O(n^2) */
/* 空间复杂度: O(n^2) */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        std::vector<vector<int>> assist_matrix = matrix;
        for (int i = matrix.size() - 1, k = 0; i >= 0; --i, ++k) {  // i -> 行
            for (int j = 0; j < matrix[0].size(); ++j) {
                assist_matrix[j][k] = matrix[i][j];
            }
        }
        matrix = assist_matrix;
    }
};

/* 两次翻转代替旋转 */
/* 时间复杂度: O(n^2) */
/* 空间复杂度: O(1) => 原地翻转 */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        for (int i = 0; i < (row >> 1); ++i) {  // 先根据水平轴线翻转
            for (int j = 0; j < col; ++j) {
                std::swap(matrix[i][j], matrix[row - i - 1][j]);
                ;
            }
        }
        for (int i = 0; i < row; ++i) {  // 再根据主对角线翻转
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
