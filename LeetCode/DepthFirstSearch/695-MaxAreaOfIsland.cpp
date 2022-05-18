/* 0 represent water, 1 represent island. */

class Solution {
public:
    // main
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int max_area = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                max_area = std::max(max_area, dfs(grid, i, j));
            }
        }
        return max_area;
    }

    // helper
    int dfs(vector<vector<int>>& grid, int x, int y) {
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == 0) return 0;
        grid[x][y] = 0;
        return 1 + dfs(grid, x - 1, y) + dfs(grid, x + 1, y) + dfs(grid, x, y - 1) + dfs(grid, x, y + 1);
    }
};
