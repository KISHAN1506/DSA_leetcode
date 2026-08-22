class Solution {
public:
    void bfs(vector<vector<char>>& grid, vector<vector<int>>& vis,
             int n, int m, queue<pair<int, int>>& q) {
        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, 1, 0, -1};

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;

            q.pop();
            for (int k = 0; k < 4; k++) {
                int nrow = row + drow[k];
                int ncol = col + dcol[k];

                if (nrow < n && nrow >= 0 && ncol < m && ncol >= 0 &&
                    grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    q.push({i, j});
                    vis[i][j] = 1;
                    bfs(grid, vis, n, m, q);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};