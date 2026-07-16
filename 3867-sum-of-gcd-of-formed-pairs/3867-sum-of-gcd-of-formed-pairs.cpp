class Solution {
public:
    typedef long long ll;
    long long gcdSum(vector<int>& nums) {
        ll n = nums.size();
        vector<int> prefMax(n);

        prefMax[0] = nums[0];
        for(int i = 1;i<n;i++){
            prefMax[i] = max(prefMax[i-1],nums[i]);
        }

        vector<int> prefGCD(n);

        for(int i = 0;i<n;i++){
            prefGCD[i] = std::gcd(nums[i],prefMax[i]);
        }

        sort(prefGCD.begin(),prefGCD.end());

        int idx = prefGCD.size()/2;

        ll sum = 0;
        for(int i = 0;i<idx;i++){
            sum += std::gcd(prefGCD[i],prefGCD[n-i-1]);
        }

        return sum;

    }
};