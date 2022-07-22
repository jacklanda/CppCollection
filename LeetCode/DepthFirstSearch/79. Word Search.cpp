/* time complexity: O(m*n) */
/* space complexity: O(m*n) */

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j)
                if (dfs(board, word, i, j, 0))
                    return true;
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, string& word, int x, int y, int word_idx) {
        if (word_idx == word.size())
            return true;
        else if (x < 0 or x >= board.size() or y < 0 or y >= board[0].size() or board[x][y] != word[word_idx])
            return false;

        char tmp = board[x][y];
        board[x][y] = '#';
        ++word_idx;

        bool res = dfs(board, word, x - 1, y, word_idx) or dfs(board, word, x + 1, y, word_idx) or dfs(board, word, x, y - 1, word_idx) or dfs(board, word, x, y + 1, word_idx);
        board[x][y] = tmp;

        return res;
    }
};
