/* time complexity: O(m*n) */
/* space complexity: O(m*n) */

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        const int length = n * n;
        // 2d vector definition: vector<vector<T>> matrix(rows, vector<T>(cols, 0));
        std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
        // simulation
        int left = 0, right = n - 1, top = 0, bottom = n - 1;
        int i = 0, num = 1;
        while (left <= right and top <= bottom) {
            for (i = left; i <= right; ++i) matrix[top][i] = num++;
            ++top;
            for (i = top; i <= bottom; ++i) matrix[i][right] = num++;
            --right;
            
            if (left > right or top > bottom) break;
            
            for (i = right; i >= left; --i) matrix[bottom][i] = num++;
            --bottom;
            for (i = bottom; i >= top; --i) matrix[i][left] = num++;
            ++left;
        }
        
        return matrix;
    }
};
