class Solution {
public:
    int totWay(int i,vector<int>& nums,vector<int>& dp){
        if(i >= nums.size()){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }

        int rob = nums[i] + totWay(i+2,nums,dp);
        int skip = totWay(i + 1, nums,dp);

        return dp[i] = max(rob,skip);
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return max(totWay(0,nums,dp),totWay(1,nums,dp));
    }
};