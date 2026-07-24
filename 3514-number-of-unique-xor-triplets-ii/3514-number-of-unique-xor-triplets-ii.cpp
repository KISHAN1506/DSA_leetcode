class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        int maxEle = *max_element(nums.begin(),nums.end());

        int T = 1;
        while(T <= maxEle){
            T *= 2;
        }

        vector<bool> s1(T,false); //to store pairXOR value
        vector<bool> s2(T,false); //to store triplet XOR value

        for(int i = 0;i<n;i++){
            for(int j  = 0;j<n;j++){
                s1[nums[i]^nums[j]] = true;
            }
        }

        for(int i = 0;i<T;i++){
            if(s1[i] == true){
                for(int& num : nums){
                    s2[i^num] = true;
                }
            }
        }

        int cnt = 0;
        for(int i = 0;i<T;i++){
            if(s2[i] == true) cnt++;
        }
        return cnt;


        // int n = nums.size();
        // unordered_set<int> s1;
        // for(int i = 0;i<n;i++){
        //     for(int j = i;j<n;j++){
        //         s1.insert(nums[i]^nums[j]);
        //     }
        // }

        // unordered_set<int> stt;
        // for(int pairXor:s1){
        //     for(int& num:nums){
        //         stt.insert(pairXor^num);
        //     }
        // }

        // return stt.size();
    }
};