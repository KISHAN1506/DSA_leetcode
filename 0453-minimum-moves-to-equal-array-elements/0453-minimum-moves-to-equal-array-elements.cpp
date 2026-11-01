class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int minVal = *min_element(nums.begin(),nums.end());
        int sum = accumulate(nums.begin(),nums.end(),0);
        // int cnt = 0;

        // for(int i = 0;i<nums.size();i++){
        //     cnt += (nums[i] - minVal);
        // }
        return sum - n*minVal;
    }
};