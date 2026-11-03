class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int medVal = nums[n/2];

        int cnt = 0;
        for(int i = 0;i<n;i++){
            cnt += abs(nums[n-1] - nums[i]);
        }
        return cnt;
    }
};