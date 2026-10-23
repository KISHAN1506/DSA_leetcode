class Solution {
public:
    void solve(vector<int> nums,vector<int> out,int index,vector<vector<int>>& ans){
        if(index >= nums.size()){
            ans.push_back(out);
            return;
        }
        // Leave Element
        solve(nums,out,index+1,ans);

        // Take Element
        int ele = nums[index];
        out.push_back(ele);
        solve(nums,out,index+1,ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> out;

        solve(nums,out,0,ans);
        return ans;
    }
};