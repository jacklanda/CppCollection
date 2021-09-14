/* DFS + 剪枝 */
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        col = board[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (dfs(board, word, i, j, 0)) return true; /* 回溯的最顶层 */
            }
        }
        return false;
    }

private:
    int row;
    int col;

    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int k) {
        if (i < 0 || j < 0 || i > row - 1 || j > col - 1 ||
            k > word.size() - 1 || board[i][j] != word[k])
            return false;
        if (k == word.size() - 1) return true;
        char tmp = board[i][j];
        board[i][j] = '\0';  // 暂时将当前字符置空
        /* 在当前节点的四个方向上进行dfs */
        bool result = dfs(board, word, i - 1, j, k + 1) ||
                      dfs(board, word, i, j + 1, k + 1) ||
                      dfs(board, word, i + 1, j, k + 1) ||
                      dfs(board, word, i, j - 1, k + 1);
        board[i][j] = tmp;  // 恢复当前字符
        return result;
    }
};
