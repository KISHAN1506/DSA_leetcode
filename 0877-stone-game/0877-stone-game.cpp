class Solution {
public:
    int solve(int i,int j,vector<int>& arr,vector<vector<int>>& dp){
        if(i > j) return 0;
        if(i == j) return arr[i];

        if(dp[i][j] != -1) return dp[i][j];

        int take_i = arr[i] - solve(i+1,j,arr,dp);
        int take_j = arr[j] - solve(i,j-1,arr,dp);

        return dp[i][j] = max(take_i,take_j);
    }

    bool stoneGame(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(0,n-1,arr,dp) >= 0;
    }
};