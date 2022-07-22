/* time complexity: O(m*n) */
/* space complexity: O(m*n) */

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    ++res;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }
    
private:
    void dfs(vector<vector<char>>& grid, int x, int y) {
        if (x < 0 or x >= grid.size() or y < 0 or y >= grid[0].size() or grid[x][y] == '0')
            return;
        
        grid[x][y] = '0';
        dfs(grid, x - 1, y);
        dfs(grid, x + 1, y);
        dfs(grid, x, y - 1);
        dfs(grid, x, y + 1);
    }
};
