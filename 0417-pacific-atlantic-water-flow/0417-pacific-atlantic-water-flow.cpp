class Solution {
public:
    void dfs(vector<vector<int>>& heights,int row,int col,int prev,vector<vector<int>>& visited){
        if(row < 0 || row>= heights.size() || col< 0 ||col>= heights[0].size()){
            return;
        }

        if(heights[row][col] < prev || visited[row][col]){
            return;
        }

        vector<int> drow = {-1,0,1,0};
        vector<int> dcol = {0,1,0,-1};
        visited[row][col] = true;
        
        for(int i = 0;i < 4;i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            dfs(heights,nrow,ncol,heights[row][col],visited);
        }

    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> result;


        vector<vector<int>> pacificVisited(n,vector<int>(m,0));
        vector<vector<int>> atlanticVisited(n,vector<int>(m,0));

        // set sides 0 
        for(int j = 0;j<m;j++){
            dfs(heights,0,j,INT_MIN,pacificVisited);
            dfs(heights,n-1,j,INT_MIN,atlanticVisited);
        }

        for(int i = 0;i<n;i++){
            dfs(heights,i,0,INT_MIN,pacificVisited);
            dfs(heights,i,m-1,INT_MIN,atlanticVisited);
        }

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(atlanticVisited[i][j] && pacificVisited[i][j]){
                    result.push_back({i,j});
                }
            }
        }

        return result;


    }
};