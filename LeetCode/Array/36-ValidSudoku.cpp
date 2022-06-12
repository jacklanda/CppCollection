/* time complexity: O(n^2) */
/* space complexity: O(1) */

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool used[9];

        for (int i = 0; i < 9; ++i) {
            // check row
            std::fill(used, used + 9, false);
            for (int j = 0; j < 9; ++j)
                if (!check(board[i][j], used)) return false;
            // check column
            std::fill(used, used + 9, false);
            for (int j = 0; j < 9; ++j)
                if (!check(board[j][i], used)) return false;
        }
        // check sub-box of 9 grids
        for (int row = 0; row < 3; ++row)
            for (int col = 0; col < 3; ++col) {
                std::fill(used, used + 9, false);
                for (int i = row * 3; i < row * 3 + 3; ++i)
                    for (int j = col * 3; j < col * 3 + 3; ++j)
                        if (!check(board[i][j], used)) return false;
            }
        return true;
    }

    bool check(char c, bool used[9]) {
        if (c == '.') return true;
        if (used[c - '1']) return false;
        return used[c - '1'] = true;
    }
};
