class Solution {
public:
    void permutations(vector<int> &nums,vector<int> &temp,vector<vector<int>>& ans){
        int n = nums.size();
        if(n == 0){
            ans.push_back(temp);
            return;
        }

        for(int i = 0;i<n;i++){
            int val = nums[i];
            temp.push_back(val);

            vector<int> new_nums = nums;
            new_nums.erase(new_nums.begin() + i);
            permutations(new_nums,temp,ans);
            temp.pop_back();
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        permutations(nums,temp,ans);
        return ans;
    }
};