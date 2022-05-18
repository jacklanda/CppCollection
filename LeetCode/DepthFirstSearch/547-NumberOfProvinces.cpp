/*  Every row in this graph represents a node.
    [[1, 1, 0],
     [1, 1, 0],
     [0, 0, 1]]
*/

class Solution {
public:
    // main
    int findCircleNum(vector<vector<int>>& isConnected) {
        if (isConnected.empty() || isConnected[0].empty()) return 0;
        int count = 0;
        vector<bool> visited(isConnected.size(), false);  // memo for status memorization
        for (int i = 0; i < isConnected.size(); ++i) {
            if (!visited[i]) {
                dfs(isConnected, visited, i);
                ++count;
            }
        }
        return count;
    }

    // helper
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int i) {
        visited[i] = true;
        for (int j = 0; j < isConnected[0].size(); ++j) {
            if (isConnected[i][j] == 1 && !visited[j]) dfs(isConnected, visited, j);
        }
    }
};
