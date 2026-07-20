class Solution {
public: 
    void bfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>>& vis,int &n,int &m,queue<pair<int,int>>& q){
        vector<int> drow = {-1,0,1,0};
        vector<int> dcol = {0,1,0,-1};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int row = it.first;
            int col = it.second;


            for(int i = 0;i<4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >=0 && nrow < n && ncol >=0 && ncol < m 
                    && grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
                        vis[nrow][ncol] = 1;
                        q.push({nrow,ncol});
                    }
            }
        }
    }


    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        int cnt = 0;
        queue<pair<int,int>> q;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    q.push({i,j});
                    vis[i][j] = 1;
                    bfs(i,j,grid,vis,n,m,q);
                    cnt++;
                }
            }
        }
        return cnt;
        
    }
};