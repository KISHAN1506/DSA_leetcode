class Solution {
public:
    void findCombs(int idx,int target,vector<int>& arr,vector<vector<int>>& ans,vector<int>& ds){
        if(idx == arr.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }

        if(arr[idx] <= target){
            ds.push_back(arr[idx]);
            findCombs(idx,target-arr[idx],arr,ans,ds);
            ds.pop_back();
        }
        findCombs(idx+1,target,arr,ans,ds);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;

        findCombs(0,target,candidates,ans,ds);

        return ans;
    }
};