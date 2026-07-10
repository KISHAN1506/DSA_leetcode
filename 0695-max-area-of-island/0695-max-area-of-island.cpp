class Solution {
public:
    int bfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& vis,int n,int m){
        queue<pair<int,int>> q;
        q.push({row,col});
        vis[row][col] = 1;

        int cnt = 1;

        vector<int> drow = {-1,0,1,0};
        vector<int> dcol = {0,1,0,-1};

        while(!q.empty()){
            pair<int,int> curr = q.front();
            q.pop();

            int row = curr.first;
            int col = curr.second;

            for(int k = 0;k<4;k++){
                int nrow = row + drow[k];
                int ncol = col + dcol[k];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
                    !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                        vis[nrow][ncol] = 1;
                        cnt++;
                        q.push({nrow,ncol});
                }
            }
        }

        return cnt;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        int maxSize = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                int size;
                if(grid[i][j] == 1 && !vis[i][j]){
                    size = bfs(i,j,grid,vis,n,m);
                    maxSize = max(maxSize,size);
                }
            }
        }
        return maxSize;
    }
};