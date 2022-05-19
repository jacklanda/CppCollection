class Solution {
public:
    // main
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) return {};
        vector<vector<int>> can_reach_both;
        int rows = heights.size(), cols = heights[0].size();
        vector<vector<bool>> can_reach_p(rows, vector<bool>(cols, false));
        vector<vector<bool>> can_reach_a(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; ++i) {
            // dfs each node along left-and-right edges of matrix
            dfs(heights, can_reach_p, heights[i][0], i, 0);
            dfs(heights, can_reach_a, heights[i][cols - 1], i, cols - 1);
        }

        for (int i = 0; i < cols; ++i) {
            // dfs each node along top-and-bottom edges of matrix
            dfs(heights, can_reach_p, heights[0][i], 0, i);
            dfs(heights, can_reach_a, heights[rows - 1][i], rows - 1, i);
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (can_reach_p[i][j] && can_reach_a[i][j]) can_reach_both.emplace_back(vector<int>{i, j});
            }
        }
        return can_reach_both;
    }

    // helper
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& can_reach, int prev_height, int x, int y) {
        if (x < 0 || y < 0 || x >= heights.size() || y >= heights[0].size() || heights[x][y] < prev_height || can_reach[x][y]) return;

        can_reach[x][y] = true;
        dfs(heights, can_reach, heights[x][y], x - 1, y);
        dfs(heights, can_reach, heights[x][y], x + 1, y);
        dfs(heights, can_reach, heights[x][y], x, y - 1);
        dfs(heights, can_reach, heights[x][y], x, y + 1);

        return;
    }
};
