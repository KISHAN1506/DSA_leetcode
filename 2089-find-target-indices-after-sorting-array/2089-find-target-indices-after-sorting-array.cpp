class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int cnt1 = 0;
        int cnt2 = 0;

        for(auto& val : nums){
            if(val < target){
                cnt1++;
            }else if(val == target){
                cnt2++;
            }
        }

        vector<int> res;
        for(int i = 0;i<cnt2;i++){
            res.push_back(cnt1++);
        }
        return res;
    }
};