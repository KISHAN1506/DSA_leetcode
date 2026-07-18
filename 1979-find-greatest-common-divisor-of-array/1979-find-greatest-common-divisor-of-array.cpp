class Solution {
public:
    int findGCD(vector<int>& nums) {
        int minVal = nums[0];
        int maxVal = nums[0];

        for(auto& it : nums){
            minVal = min(minVal,it);
            maxVal = max(maxVal,it);
        }

        return std::gcd(minVal,maxVal);
    }
};