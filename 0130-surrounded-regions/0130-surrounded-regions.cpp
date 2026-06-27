class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& vis,vector<vector<char>>& board,vector<int>& delrow,vector<int>& delcol){
        vis[i][j] = 1;
        int n = board.size();
        int m = board[0].size();
        // now check for top, bottom , left, right
        for(int k = 0;k<4;k++){
            int nrow = i + delrow[k];
            int ncol = j + delcol[k];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && board[nrow][ncol] == 'O'){
                dfs(nrow,ncol,vis,board,delrow,delcol);
            }
        }

    }
    void solve(vector<vector<char>>& board) {
        vector<int> delrow = {-1,0,+1,0};
        vector<int> delcol = {0,1,0,-1};
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        // We'll have to traverse the complete boundary

        // Traversing first and last row
        for(int j = 0;j<m;j++){
            if(!vis[0][j] && board[0][j] == 'O'){
                dfs(0,j,vis,board,delrow,delcol);
            }
            if(!vis[n-1][j] && board[n-1][j] == 'O'){
                dfs(n-1,j,vis,board,delrow,delcol);
            }
        }

        // Traversing first and last col
        for(int i = 0;i<n;i++){
            if(!vis[i][0] && board[i][0] == 'O'){
                dfs(i,0,vis,board,delrow,delcol);
            }
            if(!vis[i][m-1] && board[i][m-1] == 'O'){
                dfs(i,m-1,vis,board,delrow,delcol);
            }
        }

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!vis[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};