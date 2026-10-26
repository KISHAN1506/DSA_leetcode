class Solution {
public:
    int n,m;
    void dfs(vector<vector<int>>& grid,vector<vector<int>>& vis,int r,int c,long long& sum){
        vis[r][c] = 1;
        vector<int> drow = {-1,0,1,0};
        vector<int> dcol = {0,1,0,-1};
        for(int i = 0;i<4;i++){
            int nrow = r + drow[i];
            int ncol = c + dcol[i];

            if(nrow < n && nrow >= 0 && ncol < m && ncol >= 0
                && grid[nrow][ncol] !=0 && !vis[nrow][ncol]){
                    sum += grid[nrow][ncol];
                    dfs(grid,vis,nrow,ncol,sum);
                }
        }
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();

        int cnt = 0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] != 0 && vis[i][j] != 1){
                    long long sum = grid[i][j];
                    dfs(grid,vis,i,j,sum);
                    if(sum % k == 0){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};