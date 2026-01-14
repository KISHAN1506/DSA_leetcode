class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int xorVal = 0;
        for(int i = 0;i<nums.size();i++){
            xorVal = xorVal ^ nums[i];
        }
        return xorVal;
    }
};