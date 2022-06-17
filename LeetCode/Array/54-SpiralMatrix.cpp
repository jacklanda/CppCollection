/* time complexity: O(m*n) */
/* space complexity: O(m*n) */

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left = 0, right = matrix[0].size() - 1, top = 0, bottom = matrix.size() - 1;
        std::vector<int> res;
        int i = 0;
        while (left <= right and top <= bottom) {
            // traverse from left to right in the top row
            for (i = left; i <= right; ++i) res.emplace_back(matrix[top][i]);
            ++top;
            // traverse from top to bottom in the rightmost col
            for (i = top; i <= bottom; ++i) res.emplace_back(matrix[i][right]);
            --right;

            if (left > right or top > bottom) break;

            // traverse from right to left in the bottom row
            for (i = right; i >= left; --i) res.emplace_back(matrix[bottom][i]);
            --bottom;
            // traverse from bottom to top in the leftmost col
            for (i = bottom; i >= top; --i) res.emplace_back(matrix[i][left]);
            ++left;
        }
        return res;
    }
};
