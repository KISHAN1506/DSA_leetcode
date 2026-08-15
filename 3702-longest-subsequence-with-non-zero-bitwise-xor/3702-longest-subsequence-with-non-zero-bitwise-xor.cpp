class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xorVal = 0;
        for(int i = 0;i<n;i++){
            xorVal ^= nums[i];
        }

        if(xorVal != 0){
            return n;
        }

        // this means ki saare 0 nhi hai toh 1 value hatate hi xor will become non zero.
        for(int i = 0;i<n;i++){
            if(nums[i] != 0){
                return n-1;
            }
        }

        // saare 0 hai
        return 0;
    }
};