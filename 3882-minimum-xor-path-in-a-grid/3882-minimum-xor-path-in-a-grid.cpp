class Solution {
public:
    int m,n;
    int dfs(int i,int j,int xorVal,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
        if(i >= n || j >= m) return INT_MAX;

        if(dp[i][j][xorVal] != -1){
            return dp[i][j][xorVal];
        }

        int newXor = xorVal ^ grid[i][j];

        if(i == n-1 && j == m-1){
            return dp[i][j][xorVal] = newXor;
        }

        int right = dfs(i,j+1,newXor,grid,dp);
        int down = dfs(i+1,j,newXor,grid,dp);

        return dp[i][j][xorVal] = min(right,down);
    }

    int minCost(vector<vector<int>>& grid) {
        // top left -> bottom right
        n = grid.size();
        m = grid[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(1024, -1)));
        return dfs(0,0,0,grid,dp);

    }
};