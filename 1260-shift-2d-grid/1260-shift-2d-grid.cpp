class Solution {
public:
    void reverse(int i,int j,vector<vector<int>>& grid,int col){
        while(i<j){
            swap(grid[i/col][i%col],grid[j/col][j%col]);
            i++;j--;
        }
    }

    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int col = grid[0].size();

        int n = row*col;
        k = k%n;
        if(k == 0) return grid;

        reverse(0,n-1,grid,col);
        reverse(0,k-1,grid,col);
        reverse(k,n-1,grid,col);

        return grid;

    }
};