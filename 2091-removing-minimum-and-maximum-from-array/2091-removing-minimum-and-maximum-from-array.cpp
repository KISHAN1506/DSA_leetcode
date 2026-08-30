class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;

        int minIdx = 0;
        int maxIdx = 0;

        for(int i = 0;i<n;i++){
            if(nums[i] < nums[minIdx]){
                minIdx = i;
            }
            if(nums[i] >= nums[maxIdx]){
                maxIdx = i;
            }
        }

        int left = min(minIdx,maxIdx);
        int right = max(minIdx,maxIdx);

        return min({left+1+n-right,right+1,n-left});
        
    }
};