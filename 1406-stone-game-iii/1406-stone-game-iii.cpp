class Solution {
public:
    int solve(int i,vector<int>& arr,int n,vector<int>& dp){
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        int result = INT_MIN;
        result = max(result,arr[i] - solve(i+1,arr,n,dp));
        if(i+1<n) result = max(result,arr[i] + arr[i+1] - solve(i+2,arr,n,dp));
        if(i+2<n) result = max(result,arr[i] + arr[i+1] + arr[i+2] - solve(i+3,arr,n,dp));

        return dp[i] = result;
    }

    string stoneGameIII(vector<int>& s) {
        int n = s.size();
        vector<int> dp(n,-1);
        int result = solve(0,s,n,dp);
        if(result > 0){
            return "Alice";
        }else if(result < 0){
            return "Bob";
        }
        return "Tie";
    }
};