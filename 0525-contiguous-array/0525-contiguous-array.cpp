class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        int sum = 0;
        int maxLen = 0;
        for(int i = 0;i<n;i++){
            nums[i] == 0 ? sum += -1 : sum += 1;
            if(sum == 0){
                maxLen = i+1;
            }else if(mpp.find(sum) != mpp.end()){
                maxLen = max(maxLen,i-mpp[sum]);
            }else{
                mpp[sum] = i;
            }
        }
        return maxLen;

    }
};