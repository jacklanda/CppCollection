/* 最坏时间复杂度: O(m+n) */
/* 空间复杂度: O(1) */

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        int row = matrix.size(), col = matrix[0].size();  // 初始化矩阵的行&列
        for (int r = 0; r < row; ++r) {           // 行从上往下移动
            for (int c = col - 1; c >= 0; --c) {  // 列从右往左移动
                if (matrix[r][c] < target) {
                    // 若当前值小于目标值则行下移
                    break;
                } else if (matrix[r][c] > target) {
                    // 若当前值大于目标值则列左移
                    continue;
                } else if (matrix[r][c] == target) {
                    // 查到值则返回
                    return true;
                }
            }
        }
        return false;
    }
};
