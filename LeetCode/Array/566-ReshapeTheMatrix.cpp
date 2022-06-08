/* time complexity: O(n) */
/* space complexity: O(n) */

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if (r * c != mat.size() * mat[0].size()) return mat;
        std::vector<vector<int>> reshaped(r);
        int cur_row = 0, cur_col = 0;
        for (int i = 0; i < mat.size(); ++i) {
            for (int j = 0; j < mat[0].size(); ++j) {
                if (cur_col == c) {
                    ++cur_row;
                    cur_col = 0;
                }
                ++cur_col;
                reshaped[cur_row].emplace_back(mat[i][j]);
            }
        }
        return reshaped;
    }
};
